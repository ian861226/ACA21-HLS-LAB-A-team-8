
#ifndef __PREVENTING_AUTOMATIC_TREE_BALANCING_H__
#define __PREVENTING_AUTOMATIC_TREE_BALANCING_H__

#include "ap_int.h"

#define WIDTH_OUT 	8
#define WIDTH 		8
#define NUM_REGS	8

ap_int<WIDTH_OUT> adder_tree_unbalanced(ap_int<WIDTH> din[NUM_REGS], bool s[NUM_REGS]);

#endif
