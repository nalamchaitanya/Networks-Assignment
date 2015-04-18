//
//  Packet.c
//  HuffmanTransceiver
//
//  Created by Saipraveen B on 11/04/15.
//  Copyright (c) 2015 Saipraveen B. All rights reserved.
//

#include "Packet.h"
#include <math.h>

// Make a packet of a particular length.
Packet* _makePacket( char* data, int length )
{
    Packet* p = malloc( sizeof(Packet) );
    
    memcpy( p->data, data, length * sizeof(char) );
    p->length = length;
    
    return p;
}

// The operations of putting together a codebook and cutting it up into packets have been
// merged into one for simplicity.

void setPacketBit( int bit, Packet* p )
{
    // in progress.
    char* dat = p->data;
    dat[0];
}

Packet* variableSlice( char* data, int length, long* codebook ){
    
    int bitptr = 0;
    Packet* stream;
    
    Packet* curr;
    
    for ( i = 0; i < length; i++ ) {
        char c = data[i];
        int len = floor( log( codebook[(int)c] )/log( 2 ) );// Obtain code length. this is a slightly sub-optimal method.
        
        
        
    }
}