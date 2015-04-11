//
//  Packet.h
//  HuffmanTransceiver
//
//  Created by Saipraveen B on 11/04/15.
//  Copyright (c) 2015 Saipraveen B. All rights reserved.
//

#ifndef __HuffmanTransceiver__Packet__
#define __HuffmanTransceiver__Packet__

#include <stdio.h>

typedef struct _Packet{
    char* data;
    int length;
} Packet;

// Make a packet of a particular length.
Packet* _makePacket( char* data, int length );

// The operations of putting together a codebook and cutting it up into packets have been
// merged into one for simplicity.

Packet* variableSlice( char* data, int length, long* codebook );

#endif /* defined(__HuffmanTransceiver__Packet__) */
