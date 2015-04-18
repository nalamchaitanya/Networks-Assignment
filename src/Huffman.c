//
//  Huffman.c
//  HuffmanTransceiver
//
//  Created by Saipraveen B on 11/04/15.
//  Copyright (c) 2015 Saipraveen B. All rights reserved.
//

#include "Huffman.h"



Node* newNode( char src, int freq ){
    Node* n = malloc( sizeof(Node) );
    n->freq = freq;
    n->src = src;
    n->left = NULL;
    n->right = NULL;
    n->next = NULL;
	n->parent = NULL;
    return n;
}

Node* makeNodeList( int* frequency, int numChars ){
    Node* start = newNode( (char)0, frequency[0] );
    Node* prev = start;
    for( int i = 1; i < numChars; i++ ){
        Node* n = newNode( (char)i, frequency[i] );
        prev->next = n;
        prev = n;
    }
    return start;
}

Node* sortNodes( Node* in, Node** out ){
    // Sort by frequency.
}

Node* insertSorted( Node* arr, Node* n ){
    // insert Node into sorted array maintaining it's properties.
    Node* prev = arr;
    if( n->freq < prev->freq ){
		n->next = prev;
		return n;
    }
	
	Node* curr = arr;
    while (true) {
		if( n->freq < curr->freq ){
			prev->next = n;
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

void makeHuffmanTree( Node** out, int* frequency, int numChars ){
	Node* start = makeNodeList( frequency, numChars );
	
	Node* sorted;
	sortNodes( start, &sorted );
	
	while (true) {
		Node* n1 = sorted;
		Node* n2 = sorted->next;
		if( n2 == NULL )
			break;
		Node* merged = newNode( NULL, n1->freq + n2->freq );
		
		merged->left = n1;
		merged->right = n2;
		
		n1->parent = merged;
		n2->parent = merged;
		
		sorted = sorted->next->next;
		insertSorted( sorted, merged );
		
	}
	*out = sorted;
}
void huffmanCode( int* frequency, LLONG** codebook, int numChars ){
	
	Node* huffTree;
	makeHuffmanTree( &huffTree, frequency, numChars );
	
    long* pcodebook = malloc( sizeof( long ) * numChars );
    treeToPCodeBook( huffTree, pcodebook, 1 );// 1 is necessary or else 0000 and 000 will be encoded as the same thing.
	
	*codebook = pcodebook;
}


int fillCharSeq( char* c, int bitptr, Node* x ){
	/*
	 *(c) &= ~( ( 1 << len ) - 1 ) << bitptr;// Set bits of interest to 0.
	 *(c) |= ( ( x >> start ) & ( ( 1 << len ) - 1 ) ) << bitptr;// Set bits of interest to X[ start.. start+len ].*/
	
	/*int numBitsWrt = 0;
	 while( true ){
	 char bit = nextTreeBit( xInOut );
	 if( bit == 2 )
	 return numBitsWrt;
	 else{
	 // Set the bitptr-th the bit to the value of 'bit'
	 *(c) &= ~(1 << bitptr);
	 *(c) |= (bit << bitptr);
	 }
	 numBitsWrt++;
	 
	 if( bitptr == 7 ){
	 return numBitsWrt;
	 }
	 
	 bitptr++;
	 }*/
	
	return _fillCharSeq( c, bitptr, x );
}

char setBit( char* c, int bitptr, char bit ){
	*(c) &= ~(1 << bitptr);
	*(c) |= (bit << bitptr);
}

char traceBit( Node* x ){
	if( x->parent->left == x )
		return 0;
	else
		return 1;
}
int _fillCharSeq( char* c, int bitptr, Node* x ){
	if( x->parent->parent == NULL ){
		// Reached the top
		// Set bit.
		char bit = traceBit( x );
		setBit( c, bitptr, bit );
		return bitptr + 1;
	}else{
		// Go up the tree and set the corresponding bits on the way down.
		int bitptr = _fillCharSeq( c + (bitptr/8), bitptr, x->parent );
		// We use recursion to set bits from the top rather than form the bottom.
		char bit = traceBit( x );
		setBit( c, bitptr, bit );
		return bitptr + 1;
	}
}

void encode( char* data, int length, Node** codebook, char* buffer, int* outLength ){
	
	*outLength = 0;
	int bitptr = 0;
	
	char* curr = buffer;
	
	int i;
	for ( i = 0; i < length; i++ ) {
		char c = data[i];
		// Note here that while computing codebook lengths
		int len = floor( log( codebook[(int)c] )/log( 2 ) );// Obtain code length. this is a slightly sub-optimal method.
		int xPtr = 0;
		
		// Retreive N-bit encoding: Form from
		Node* x = codebook[(int)c];
		
		
		
		
		// Calculate the start ptr for writing into current char.
		int wrtPtr = bitptr;
		
		// transfer bits from x[ xPtr ... xPtr + wrtLen ] to curr[ wrtPtr ... wrtPtr + wrtLen ];
		int finalPtr = fillCharSeq( curr, wrtPtr, x );
		*outLength+= (finalPtr/8) + 1;
		
		// If initially the pointer pointed to an empty char, reduce one added char.
		if( bitptr % 8 == 0 )
			*outLength --;
		
		// Set the current ptr to new bit ptr.
		bitptr = finalPtr;
		
	}
	
}


