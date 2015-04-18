//
//  Huffman.c
//  HuffmanTransceiver
//
//  Created by Saipraveen B on 11/04/15.
//  Copyright (c) 2015 Saipraveen B. All rights reserved.
//

#include "Huffman.h"



typedef struct _Node{
    int freq;
    char src;
    
    // for the huffman tree.
    Node* left;
    Node* right;
    
    // holds the next pointer.
    Node* next;
    
} Node;

Node* newNode( char src, int freq ){
    Node* n = malloc( sizeof(Node) );
    n->freq = freq;
    n->src = src;
    n->left = NULL;
    n->right = NULL;
    n->next = NULL;
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

Node* sortNodes( Node* in, Node** out )
{
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

void treeToPCodeBook( Node* root, long* pcodebook, long code ){
    if( root->left == NULL ){
        pcodebook[root->src] = code;
    }else{
        treeToPCodeBook( root->left, pcodebook, code*2 + 1 );
        treeToPCodeBook( root->right, pcodebook, code*2 + 0 );
    }
}

void huffmanCode( int* frequency, long** codebook, int numChars ){
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
        
        sorted = sorted->next->next;
        insertSorted( sorted, merged );
        
    }
    
    long* pcodebook = malloc( sizeof( long ) * numChars );
    treeToPCodeBook( sorted, pcodebook, 1 );// 1 is necessary or else 0000 and 000 will be encoded as the same thing.
	
	*codebook = pcodebook;
}
