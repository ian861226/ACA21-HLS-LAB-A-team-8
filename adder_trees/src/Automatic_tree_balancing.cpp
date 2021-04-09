
#include "Automatic_tree_balancing.h"

ap_int<WIDTH_OUT> adder_tree_balanced (ap_int<WIDTH> din[NUM_REGS] ) {
	ap_int<WIDTH_OUT> acc = 0;
	for (int i=0; i!=NUM_REGS; i++)
		acc += din[i];
	return acc;
}
