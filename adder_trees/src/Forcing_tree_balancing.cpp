
#include "Forcing_tree_balancing.h"

ap_int<WIDTH_OUT> adder_tree_rebalanced(ap_int<WIDTH> din[NUM_REGS], bool s[NUM_REGS]){
	#pragma HLS ARRAY_PARTITION variable=s complete dim=1
	#pragma HLS ARRAY_PARTITION variable=din complete dim=1
	#pragma HLS PIPELINE II=1

	ap_int<WIDTH_OUT> acc = 0;
	ap_int<WIDTH> tmp[NUM_REGS];

	copied_loop:for(int i=0;i!=NUM_REGS;i++) {
		#pragma HLS UNROLL
		tmp[i] = din[i];
	}
	operate_loop:for(int i=0;i!=NUM_REGS;i++) {
		#pragma HLS UNROLL
		acc += s[i] ? tmp[i] : (ap_int<WIDTH>)0;
	}

	return acc;
}
