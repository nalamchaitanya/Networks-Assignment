//
//  ChannelCoder.c
//  HuffmanTransceiver
//
//  Created by Saipraveen B on 16/04/15.
//  Copyright (c) 2015 Saipraveen B. All rights reserved.
//

#include "ChannelCoder.h"
#include "CRC.h"
#define CRC_BITS 4
#define CRC_LENGTH 1
#include <stdlib.h>
#include <string.h>
// TODO: Include the CRC algo header.

void makeCRC( char* data, int length, char* buffer ){
    buffer[0] = 0;
    return;
}
// Encode the packet's contents by adding a CRC to the end. Note: this lengthens the channel
void channelCode( Packet* p ){
   
    char parity = getParity(p->data,p->length);
    // Concatenate the data to the end of the buffer.
    // TODO: Make sure no errors arise because the buffer in question isn't null-terminated.
    char* temp = (char*)malloc(sizeof(char)*2);
    *temp = parity;
    *(temp+1) = '\0';
    strcat( p->data, &parity );
    // Increment length.
    p->length += 1;
}

// Check the packet's CRC bits.
int channelDetect( Packet* p ){
    char parity = getParity(p->data,p->length);
    char checkParity = channelDecode(p);
    if(parity == checkParity)
        return 1;
    else
        return 0;
}

// Remove the CRC bits from the Packet.
char channelDecode( Packet* p ){
    char parity = *(p->data+p->length-1);
    p->data+(p->length-1) = '\0';
    p->length --;   // Just reduce the length.
    return parity;
}
