#include <iostream>
#include "ap_int.h"
#include "accumulator.h"

using namespace std;

void accumulator(ap_int<Width> din[Num_reg], ap_int<Width + log2_Num_reg>* dout) {
	*dout = acc_tmpl<Width, Num_reg, log2_Num_reg>(din);
}

