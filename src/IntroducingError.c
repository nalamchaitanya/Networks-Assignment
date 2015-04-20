//
//  IntroducingError.c
//  HuffmanTransceiver
//
//  Created by Nalam V S S Krishna Chaitanya on 11/04/15.
//  Copyright (c) 2015 Nalam V S S Krishna Chaitanya. All rights reserved.
//


void introduceError(char* data,float pe)
{
	if(pe<0&&pe>1)
		exit(0);
	int i,j;
	float trial;
	for(i=0;char[i]!='\0';i++)
	{
		for(j=0;j<7;j++)
		{
			trial = rand()/RAND_MAX;
			if(trial<pe)
				setBit(data+i,j,getInverseBit(data[i],j));
		}
	}
}

void setBit( char* c, int bitptr, char bit )
{
	*(c) &= ~(1 << bitptr);
	*(c) |= (bit << bitptr);
}

char getInverseBit(char c, int bitptr)
{
	c = ~c;
	return ((c&(1<<bitptr))>>bitptr);
}