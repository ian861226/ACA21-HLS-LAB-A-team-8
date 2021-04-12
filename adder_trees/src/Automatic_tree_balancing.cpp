
#include "Automatic_tree_balancing.h"

ap_int<WIDTH_OUT> adder_tree_balanced (ap_int<WIDTH> din[NUM_REGS] ) {
	#pragma HLS ARRAY_PARTITION variable=din complete dim=1
	#pragma HLS PIPELINE

	ap_int<WIDTH_OUT> acc = 0;
	adder_loop:for (int i=0; i!=NUM_REGS; i++) {
		#pragma HLS UNROLL
		acc += din[i];
	}
	return acc;
}

