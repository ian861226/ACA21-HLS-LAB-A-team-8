#ifndef  __ACCUM_TMPL__
#define  __ACCUM_TMPL__
#include "ap_int.h"
#include "math.h"


const int Width = 8;
const int Num_reg = 4;
const int log2_Num_reg = 2;

template<int W, int N, int l>
ap_int<W + l> acc_tmpl(ap_int<W> din[N]) {
	ap_int< W + l> acc;
	acc = 0;
	ACCUM: for (int i = 0; i < N; ++i)
		acc += din[i];
	return acc;
}

void accumulator(ap_int<Width> din[Num_reg], ap_int<Width + log2_Num_reg>* dout);

#endif
