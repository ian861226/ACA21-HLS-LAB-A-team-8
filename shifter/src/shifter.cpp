#include <iostream>
#include "ap_int.h"
#include "shifter.h"

using namespace std;

void shifter(ap_uint<3> mode, ap_uint<NUM_BITS> din, ap_uint<CTRL_BITS> s, ap_uint<NUM_BITS>* dout) {
    switch(mode) {
    case 0:
    	*dout = barrel_shift_al(din, s);
    	break;
    case 1:
    	*dout = barrel_shift_ar(din, s);
    	break;
    case 2:
    	*dout = barrel_shift_rr(din, s);
    	break;
    case 3:
    	*dout = barrel_shift_ll(din, s);
    	break;
    case 4:
    	*dout = barrel_shift_lr(din, s);
    	break;
    case 5:
    	*dout = barrel_shift_lr_const(din, s);
    	break;
    case 6:
    	*dout = shift_mask_dynamic(din);
    	break;
    case 7:
    	*dout = shift_mask_static(din);
		break;
    }
}

ap_int<NUM_BITS> barrel_shift_al(ap_int<NUM_BITS> din, ap_uint<CTRL_BITS> s) {
	return din << s;
}

ap_int<NUM_BITS> barrel_shift_ar(ap_int<NUM_BITS> din, ap_uint<CTRL_BITS> s) {
	return din >> s;
}

ap_uint<NUM_BITS> barrel_shift_rr(ap_uint<NUM_BITS> din, ap_uint<CTRL_BITS> s) {
	ap_uint<4> stmp =  s % NUM_BITS;
	return (din >> stmp) | (din << (NUM_BITS-stmp));
}

ap_uint<NUM_BITS> barrel_shift_ll(ap_uint<NUM_BITS> din, ap_uint<CTRL_BITS> s) {
	return din << s;
}

ap_uint<NUM_BITS> barrel_shift_lr(ap_uint<NUM_BITS> din, ap_uint<CTRL_BITS> s) {
	return din >> s;
}

ap_uint<NUM_BITS> barrel_shift_lr_const(ap_uint<NUM_BITS> din, ap_uint<CTRL_BITS> s) {
	ap_uint<NUM_BITS> tmp = din;
	if(s == 1)
		tmp >>= 1;
	else if(s == 5)
		tmp >>= 5;

	return tmp;
}

ap_uint<NUM_BITS> shift_mask_dynamic(ap_uint<NUM_BITS> din) {
	ap_uint<NUM_BITS> acc = 0;
	LOOP: for(int i = 0; i < NUM_BITS; ++i)
		acc += (din >> i) & 1;
	return acc;
}

ap_uint<NUM_BITS> shift_mask_static(ap_uint<NUM_BITS> din) {
	ap_uint<NUM_BITS> acc = 0;
	ap_uint<NUM_BITS> tmp = din;

	LOOP: for(int i = 0; i < NUM_BITS; ++i) {
		acc += tmp & 1;
		tmp >>= 1;
	}
	return acc;
}
