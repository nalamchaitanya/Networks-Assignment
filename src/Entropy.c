//
//  Entropy.h
//  HuffmanTransceiver
//
//  Created by Nalam V S S Krishna Chaitanya on 11/04/15.
//  Copyright (c) 2015 Nalam V S S Krishna Chaitanya. All rights reserved.
//


#include "include/Entropy.h"
#include <math.h>
#include <stdlib.h>

double calculateEntropy( char* data, int size )
{
    // Calculate entropy for given data and return it.
    long *freq = calculateFrequency(data,size);
    double length = size;
    double *prob = (double*)malloc(sizeof(double)*256);
    double entropy;
    entropy = 0;
    int i;
    for(i =0;i<256;i++)
    {
    	prob[i] = freq[i]/length;
    	entropy+=prob[i]*log(prob[i])/log(2);
    }
    return entropy;
}

long* calculateFrequency(char* data,int size)
{
	long *freq = (long*)malloc(sizeof(long)*256);
    int i;
    for(i=0;i<256;i++)
    {
    	freq[i] = 0;
    }
    i = 0;
    while(i<size)
    {
    	freq[(int)(data[i])]++;
    	i++;
    }
    return freq;   
} 
