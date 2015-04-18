//
//  Encoder.c
//  HuffmanTransceiver
//
//  Created by Saipraveen B on 16/04/15.
//  Copyright (c) 2015 Saipraveen B. All rights reserved.
//

#include "Encoder.h"
#include "Huffman.h"
#include "Packet.h"

Packet* sourceCode( char* data, int length, int pSize ){
    // Get frequencies of Char data here.
    int* frequency;
    // ---
    LLONG* codebook;// Max-length 128-bit codes.
    
    char* buffer = malloc( sizeof( char ) * length );
    int finalLen = 0;
    
    // Produce the huffman codebook.
    encode( char* data, buffer, &finalLen );
    
    
    // Encode and Slice into packets.
    Packet* packets = makePacketStream( data, length, pSize );
    
    return packets;
}