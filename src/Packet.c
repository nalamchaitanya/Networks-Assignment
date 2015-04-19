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

Packet* _makeEmptyPacket( int length ){
    Packet* p = malloc( sizeof(Packet) );
    p->data  = calloc( length, sizeof( char ) );
    //memcpy( p->data, data, length * sizeof(char) );
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



int chainLength( Packet* p ){
    int i = 0;
    while( true ){
        i++;
        p = p->next;
        if( !p )
            return i;
    }
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

char nextTreeBit( Node** bottom ){
    Node* n = *(bottom);
    
    if( n->parent == NULL ){
        return 2;
    }
    
    *(bottom) = n->parent;
    if( n->parent->left == n )
        return 0;
    else
        return 1;
    
}


Packet* makePacketStream( char* data, int length, int psize ){
    Packet* start;
    Packet* curr;
    for( int i = 0; i < length/psize; i++ ){
        if( curr == NULL ){
            curr = makeEmptyPacket( psize );
        }
        curr->data = data + i*psize;
        curr = curr->next;
    }
    return curr;
}