//
//  ChannelCoder.h
//  HuffmanTransceiver
//
//  Created by Saipraveen B on 16/04/15.
//  Copyright (c) 2015 Saipraveen B. All rights reserved.
//

#ifndef __HuffmanTransceiver__ChannelCoder__
#define __HuffmanTransceiver__ChannelCoder__

#include <stdio.h>

// Encode the packet's contents by adding a CRC to the end. Note: this lengthens the channel
void channelCode( Packet* p );

// Check the packet's CRC bits.
int channelDetect( Packet* p );

// Remove the CRC bits from the Packet.
void channelDecode( Packet* p );

#endif /* defined(__HuffmanTransceiver__ChannelCoder__) */
