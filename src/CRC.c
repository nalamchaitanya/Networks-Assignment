//
//  CRC.h
//  HuffmanTransceiver
//
//  Created by Nalam V S S Krishna Chaitanya on 11/04/15.
//  Copyright (c) 2015 Nalam V S S Krishna Chaitanya. All rights reserved.
//

#include "include/CRC.h"
#include "math.h"
#include "string.h"

char* getCRC(char *packet,int packetSize,char *plyn,int plynSize,int crcSize)
{
	char *temp = (char*)malloc(sizeof(char)*crcSize);
	int i;
	for(i = 0;i<crcSize;i++)
	{
		temp[i] = '0';
	}
	temp = strcat(packet,temp);
	char *a;
	for(i=0;i<packetSize;i++)
	{
		if(packet[i]!='0')
		{
			replace(i,packet,bitXOR(i,packet,plyn,plynSize));
		}
	}
	return packet+packetSize;
}

char* bitXOR(int index,char *b1,char *plyn,int plynSize)
{
	int i;
	char *temp = (char*)malloc(sizeof(char)*plynSize);
	for(i = index;i<index+plynSize;i++)
	{
		temp[i-index] = b1[i];
	}
	long int a = parseInt(temp,plynSize);
	long int b = parseInt(plyn,plynSize);
	free(temp);
	return parseBin(a^b,plynSize);
}

void replace(int index,char *str,char *replace)
{
	int i;
	for(i = index;replace[i]!='\0';i++)
	{
		str[i] = replace[i-index];
	}
	return;
}

long int parseInt(char* binaryString,int size)
{
	int value,i;
	value = 0;
	int power;
	power = 1;
	for(i=size-1;i>=0;i--)
	{
		if(binaryString[i]=='1')
			value += power;
		power=2*power;
	}
	return value;
}

char* parseBin(long int data,int size)
{
	char *binaryString = (char*)malloc(sizeof(char)*size);
	for(i=size-1;i>=0;i--)
	{
		binaryString[i] = (char)('0'+data%2);
		data = data/2;
	}
	return binaryString;
}

char* appendCRC(char* packet,char* crc)
{
	return strcat(packet,crc);
}

//gives the parity 
char getParity(char *packet,int size)
{
	char parity = '\0';
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<8;j++)
			parity ^= getBit(packet+i,j);
	}
	return parity;
}

//appends it to packet
void appendParity(char *packet,int size,char parity)
{
	setBit(packet+size-1,0,parity);
}

/* Helper functions setBit and traceBit */
void setBit( char* c, int bitptr, char bit ){
	*(c) &= ~(1 << bitptr);
	*(c) |= (bit << bitptr);
}

char getBit(char* c,int bitptr)
{
	char temp = *c;
	temp &= (1<<bitptr);
	temp = temp>>bitptr;
	return temp;
}
