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
    struct _Packet* next;
    char* data;
    int length;
} Packet;

// Make a packet of a particular length.
Packet* _makePacket( char* data, int length );

// Splices the encoded data into packets.
Packet* makePacketStream( char* data, int length, int psize );

#endif /* defined(__HuffmanTransceiver__Packet__) */
