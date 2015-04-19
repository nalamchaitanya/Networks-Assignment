//
//  Encoder.h
//  HuffmanTransceiver
//
//  Created by Saipraveen B on 16/04/15.
//  Copyright (c) 2015 Saipraveen B. All rights reserved.
//

#ifndef __HuffmanTransceiver__Encoder__
#define __HuffmanTransceiver__Encoder__

#include <stdio.h>
#include "Huffman.h"

char* sourceCode( char* data, int length );

char* sourceDecode( char* data, int length, Node* tree );

#endif /* defined(__HuffmanTransceiver__Encoder__) */
