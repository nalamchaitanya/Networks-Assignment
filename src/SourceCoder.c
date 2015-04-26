//
//  Encoder.c
//  HuffmanTransceiver
//
//  Created by Saipraveen B on 16/04/15.
//  Copyright (c) 2015 Saipraveen B. All rights reserved.
//

#include "SourceCoder.h"
#include "Huffman.h"
#include "Packet.h"
#include "Entropy.h"
#include <stdlib.h>

char* sourceCode( char* data, int length ){
    // Get frequencies of Char data here.
    long* frequency = caluclateFrequency(data,length);
    // ---
    
    char* buffer = malloc( sizeof( char ) * length );
    int finalLen = 0;
    
    // Produce the huffman codebook.
    //encode( data, buffer, &finalLen );
    
    Node* root;
    
    Node** baseList = malloc( sizeof( Node* ) * 10 );
    makeHuffmanTree( &root, frequency, 256, baseList );
    
    encode( data, length, baseList, buffer, &finalLen );
    
    // Encode and Slice into packets.
    return buffer;
}

char* sourceDecode( char* data, int length, long* frequency, int expectedLen ){
    
    Node* root;
    
    Node** baseList = malloc( sizeof( Node* ) * 10 );
    makeHuffmanTree( &root, frequency, 256, baseList );
    
    int finalLen = 0;
    char* buffer = malloc( sizeof( char ) * expectedLen );
    //decode( data, length, root, buffer, &finalLen );
    return buffer;
    
}
