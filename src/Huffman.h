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
    int freq;
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
void makeHuffmanTree( Node** out, int* frequency, int numChars, Node** pListBuf );

#endif /* defined(__HuffmanTransceiver__Huffman__) */
