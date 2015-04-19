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
    Node* left;
    Node* right;
    // for reverse trace.
    Node* parent;
    
    // holds the next pointer.
    Node* next;
    
} Node;


typedef struct _BitStream{
    
    char bit;
    BitStream* next;
    
} BitStream;

void huffmanCode( int* frequency, BitStream** codebook );

#endif /* defined(__HuffmanTransceiver__Huffman__) */
