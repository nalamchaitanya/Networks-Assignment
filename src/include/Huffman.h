//
//  Huffman.h
//  HuffmanTransceiver
//
//  Created by Saipraveen B on 11/04/15.
//  Copyright (c) 2015 Saipraveen B. All rights reserved.
//

#ifndef __HuffmanTransceiver__Huffman__
#define __HuffmanTransceiver__Huffman__

#include <stdio.h>

typedef long long LLONG;


typedef struct _Node{
    long freq;
    char src;
    
    // for the huffman tree.
    struct _Node* left;
    struct _Node* right;
    // for reverse trace.
    struct _Node* parent;
    
    // holds the next pointer.
    struct _Node* next;
    
} Node;


typedef struct _BitStream{
    
    char bit;
    struct _BitStream* next;
    
} BitStream;


void encode( char* data, int length, Node** codebook, char* buffer, int* outLength );
void makeHuffmanTree( Node** out, long* frequency, int numChars, Node** pListBuf );
void decode( char* data, int length, Node* root, char* buffer, int expected );

char traceBit( Node* x );
void setBit( char* c, int bitptr, char bit );
void fillCharSeq( char* c, int* bitptr, Node* x );

#endif /* defined(__HuffmanTransceiver__Huffman__) */
