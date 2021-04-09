
#ifndef __AUTOMATIC_TREE_BALANCING_H__
#define __AUTOMATIC_TREE_BALANCING_H__

#include "ap_int.h"

#define WIDTH_OUT 	8
#define WIDTH 		8
#define NUM_REGS	8

ap_int<WIDTH_OUT> adder_tree_balanced (ap_int<WIDTH> din[NUM_REGS] );

#endif
