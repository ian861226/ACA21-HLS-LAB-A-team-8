
#include "Preventing_Automatic_tree_balancing.h"

ap_int<WIDTH_OUT> adder_tree_unbalanced(ap_int<WIDTH> din[NUM_REGS], bool s[NUM_REGS]) {
	#pragma HLS INTERFACE ap_fifo port=s
	#pragma HLS INTERFACE ap_fifo port=din

	ap_int<WIDTH_OUT> acc = 0;
	ap_int<WIDTH> tmp[NUM_REGS];
	copied_loop:for(int i=0;i!=NUM_REGS;i++) {
		#pragma HLS UNROLL
		tmp[i] = din[i];
	}

	operate_loop:for(int i=0;i!=NUM_REGS;i++) {
		#pragma HLS UNROLL
		if(s[i])
			acc += tmp[i];
	}

	return acc;
}
