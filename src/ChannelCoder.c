//
//  ChannelCoder.c
//  HuffmanTransceiver
//
//  Created by Saipraveen B on 16/04/15.
//  Copyright (c) 2015 Saipraveen B. All rights reserved.
//

#include "ChannelCoder.h"
#define CRC_LENGTH 4
#include <stdlib.h>
#include <string.h>
// TODO: Include the CRC algo header.

// Encode the packet's contents by adding a CRC to the end. Note: this lengthens the channel
void channelCode( Packet* p ){
    char *buffer = malloc( sizeof( char ) * CRC_LENGTH );
    makeCRC( p->data, p->length, buffer );// Put other CRC info if necessary.
    
    // Concatenate the data to the end of the buffer.
    strcat( p->data, buffer );
    // Increment length.
    p->length += CRC_LENGTH;
    
}

// Check the packet's CRC bits.
int channelDetect( Packet* p ){
    char* crc = p->data + ( p->length - 1 - CRC_LENGTH );
    char *buffer = malloc( sizeof( char ) * CRC_LENGTH );
    makeCRC( p->data, p->length - CRC_LENGTH, buffer );// Put other CRC info if necessary.
    int cmp = strcmp( crc, buffer );
    if( cmp == 0 ){
        return 1;
    }else return 0;
}

// Remove the CRC bits from the Packet.
void channelDecode( Packet* p ){
    p->length -= CRC_LENGTH;// Just reduce the length.
}
