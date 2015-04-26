//
//  Huffman.c
//  HuffmanTransceiver
//
//  Created by Saipraveen B on 11/04/15.
//  Copyright (c) 2015 Saipraveen B. All rights reserved.
//

#include "Huffman.h"

#include <stdlib.h>
#include <stdio.h>

Node* newNode( char src, int freq ){
    Node* n = (Node*) malloc( sizeof(Node) );
    n->freq = freq;
    n->src = src;
    n->left = NULL;
    n->right = NULL;
    n->next = NULL;
	n->parent = NULL;
    return n;
}

Node* makeNodeList( long* frequency, int numChars ){
    Node* start = newNode( (char)0, frequency[0] );
    Node* prev = start;
    for( int i = 1; i < numChars; i++ ){
        Node* n = newNode( (char)i, frequency[i] );
        prev->next = n;
        prev = n;
    }
    return start;
}

int sizeOfList(Node* in)
{
	int i = 0;
	Node *temp = in;
	while(temp!=NULL)
	{
		i++;
		temp = temp->next;
	}
	return i;
}

Node* convertListToArray(Node* in, int size)
{
	Node* arr = (Node*)malloc(sizeof(Node)*size);
	Node* temp = in;
	int i = 0;
	while(temp!=NULL)
	{
		arr[i] = *temp;
		i++;
		temp = temp->next;
	}
	return arr;
}

int Comparator(const void *a,const void *b)
{
	int p,q;
	p = (*(Node*)a).freq;
	q = (*(Node*)b).freq;
	return (p-q);
}


void relink( Node* n, int length ){
	int i;
	for ( i = 0; i < length - 1; i++ ) {
		n->next = ( n + 1 );
		n++;
	}
    n->next = NULL;
}

void sortNodes( Node* in, Node** out, Node** oldCopy )
{
    // Sort by frequency.
    //Converts the list into array.
    int len = sizeOfList( in );
    Node* arr = convertListToArray( in, len);
    *oldCopy = arr;
    qsort( arr, len, sizeof(Node), Comparator );
	relink( arr, len );
    *out = arr;

}

Node* insertSorted( Node* arr, Node* n ){
    // insert Node into sorted array maintaining it's properties.
    Node* prev = arr;
    if( n->freq < prev->freq ){
		n->next = prev;
		return n;
    }
	
	Node* curr = arr;
    while (1) {
		if( curr == NULL ){
            prev->next = n;
            n->next = NULL;
            break;
        }
        if( n->freq < curr->freq ){
			if( prev != curr ){
                prev->next = n;
            }
			n->next = curr;
			break;
		}
		prev = curr;
		curr = curr->next;
    }
    
	return arr;
}

void treeToPCodeBook( Node* root, LLONG* pcodebook, LLONG code ){
    if( root->left == NULL ){
        pcodebook[root->src] = code;
    }else{
        treeToPCodeBook( root->left, pcodebook, code*2 + 1 );
        treeToPCodeBook( root->right, pcodebook, code*2 + 0 );
    }
}

void makeHuffmanTree( Node** out, long* frequency, int numChars, Node** pListBuf ){
	Node* start = makeNodeList( frequency, numChars );
	
	// Store base pointers in the list for quick access while encoding.
	
	Node* sorted;
    Node* arr;
	//Assume sorted is a new array.


	sortNodes( start, &sorted, &arr );
	
	for (int i = 0; i < numChars; i++ ) {
		pListBuf[i] = arr + i;
	}

	while (1) {
		Node* n1 = sorted;
		Node* n2 = sorted->next;
		if( n2 == NULL )
			break;
		Node* merged = newNode( 0, n1->freq + n2->freq );
		
        printf("Merging %ld, %ld\n", n1->freq, n2->freq);fflush( stdout );
		merged->left = n1;
		merged->right = n2;
		
		n1->parent = merged;
		n2->parent = merged;
		
		sorted = (sorted->next->next);
        if( sorted != NULL )
		    sorted = insertSorted( sorted, merged );
        else
            sorted = merged;
	}
	*out = sorted;
	
}

/* Helper functions setBit and traceBit */
void setBit( char* c, int bitptr, char bit ){
	*(c) &= ~(1 << bitptr);
	*(c) |= (bit << bitptr);
}

char traceBit( Node* x ){
	if( x->parent->left == x )
		return 0;
	else
		return 1;
}

void abcdefg( char* c, Node* x, int* bitptr ){
    printf("BIT:%d", *bitptr);fflush(stdout);
	if( x->parent->parent == NULL ){
		// Reached the top
		// Set bit.
		char bit = traceBit( x );
		setBit( c + (int)((*bitptr)/8), (*bitptr)%8, bit );
        printf("T:%d@%d\n", (int)(bit), *bitptr);fflush(stdout);
        
        (*bitptr)++;
		return;
	}else{
		// Go up the tree and set the corresponding bits on the way down.
        //printf("In:%c@%d", x->src, *bitptr);
		abcdefg( c, x->parent, bitptr );
		// We use recursion to set bits from the top rather than form the bottom.
		char bit = traceBit( x );
		setBit( c + (int)((*bitptr)/8), (*bitptr)%8, bit );
        printf("S:%d@%d\n", (int)(bit), *bitptr );fflush(stdout);

		(*bitptr)++;
        return;
	}
}

void fillCharSeq( char* c, int* bitptr, Node* x ){	
	abcdefg( c, x, bitptr);
}





void encode( char* data, int length, Node** codebook, char* buffer, int* outLength ){
	
	*outLength = 0;
	int bitptr = 0;
	
	char* curr = buffer;
	
	int i;
	for ( i = 0; i < length; i++ ) {
		char c = data[i];
		// Note here that while computing codebook lengths
		//int len = floor( log( codebook[(int)c] )/log( 2 ) );// Obtain code length. this is a slightly sub-optimal method.
		//int xPtr = 0;
		
		// Retreive N-bit encoding: Form from
		Node* x = codebook[c];
			
		// Calculate the start ptr for writing into current char.
		// transfer bits from x[ xPtr ... xPtr + wrtLen ] to curr[ wrtPtr ... wrtPtr + wrtLen ];
		fillCharSeq( curr, &bitptr, x );
		//*outLength+= (finalPtr/8) + 1;
        printf("written: %c\n" ,c);
		// If initially the pointer pointed to an empty char, reduce one added char.
		//if( bitptr % 8 == 0 )
		//	(*outLength) --;
		
		// Set the current ptr to new bit ptr.
		//bitptr = finalPtr;
		
	}
	
}


char getBit( char* data, int bitptr ){
	char c = *(data + (bitptr/8));
	return ( ( c & ( 1 << bitptr%8 ) ) == 0 )? 0 : 1;
}

void decode( char* data, int length, Node* root, char* buffer, int expected ){
	Node* curr = root;
	int bitptr = 0;
	
	int bufferPtr = 0;
	while(1){
		char c = getBit( data, bitptr );
		if( c == 0 )
			curr = curr->left;
		else
			curr = curr->right;
		if( curr->left == NULL ){
			buffer[bufferPtr] = curr->src;
            expected--;
			bufferPtr++;
			curr = root;
		}
		bitptr++;
		if( expected == 0 )
			break;
	}
	return;
}

