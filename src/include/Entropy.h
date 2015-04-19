//
//  Entropy.h
//  HuffmanTransceiver
//
//  Created by Nalam V S S Krishna Chaitanya on 11/04/15.
//  Copyright (c) 2015 Nalam V S S Krishna Chaitanya. All rights reserved.
//



#include <math.h>

#ifndef HuffmanTransceiver_Entropy_h
#define HuffmanTransceiver_Entropy_h

double calculateEntropy( char* data, int size );

long int* calculateFrequency(char* data,int size);

#endif
