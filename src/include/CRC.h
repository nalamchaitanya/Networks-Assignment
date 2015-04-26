//
//  CRC.h
//  HuffmanTransceiver
//
//  Created by Nalam V S S Krishna Chaitanya on 11/04/15.
//  Copyright (c) 2015 Nalam V S S Krishna Chaitanya. All rights reserved.
//

#ifndef CRC_h
#define CRC_h

//gets the crc (not generalized i.e long int used)
char* getCRC(char *packet,int packetSize,char *plyn,int plynSize,int crcSize);

//appends it to the packet.
char* appendCRC(char* packet,char* crc);

//gives the parity 
char* getParity(char *packet,int size);

//appends it to packet
char* appendParity(char *packet,char *parity);

#endif