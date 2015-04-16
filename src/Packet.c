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
Packet* _makePacket( char* data, int length ){
    Packet* p = malloc( sizeof(Packet) );
    
    memcpy( p->data, data, length * sizeof(char) );
    p->length = length;
    
    return p;
}

// The operations of putting together a codebook and cutting it up into packets have been
// merged into one for simplicity.

void setPacketBit( int bit, Packet* p ){
    // in progress.
    char* dat = p->data;
    dat[0];
}

void fillChar( char* c, int bitptr, LLONG x, int len, int start ){
    *(c) &= ~( ( 1 << len ) - 1 ) << bitptr;// Set bits of interest to 0.
    *(c) |= ( ( x >> start ) & ( ( 1 << len ) - 1 ) ) << bitptr;// Set bits of interest to X[ start.. start+len ].
}

void fillPacket( Packet* p, int bitptr, LLONG x, int len, int start ){
    while( true ){
        if (bitptr % 8 != 0 ) {
            fillChar( p->data + (bitptr / 8), bitptr % 8, x, len, start );
            if( len < 8 ){
                return;
            }else{
                len -= bitptr % 8;
            }
            
        }else{
            fillChar( p->data + (bitptr / 8), 0, x, len, start );
            if( len < 8 )
                return;
            
            len -= 8;
        }
    }
}

Packet* variableSlice( char* data, int length, LLONG* codebook ){
    
    int bitptr = 0;
    Packet* stream;
    
    Packet* curr;
    
    for ( i = 0; i < length; i++ ) {
        char c = data[i];
        // Note here that while computing codebook lengths
        int len = floor( log( codebook[(int)c] )/log( 2 ) );// Obtain code length. this is a slightly sub-optimal method.
        
        LLONG x = codebook[(int)c];
        while( true ){
            if (bitptr % length != 0 ) {
                fillChar( p + (bitptr / length), bitptr % length, x, len, start );
                if( len < length ){
                    return;
                }else{
                    len -= bitptr % length;
                }
                
            }else{
                fillPacket( p + (bitptr / length), 0, x, len, start );
                if( len < length )
                    return;
                
                len -= length;
            }
        }
        
    }
    
}