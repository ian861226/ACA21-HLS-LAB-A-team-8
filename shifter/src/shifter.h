#ifndef  __BARREL_SHIFT__
#define  __BARREL_SHIFT__
#include "ap_int.h"

#define NUM_BITS 8
#define CTRL_BITS 4

void shifter(ap_uint<4> mode, ap_uint<NUM_BITS> din, ap_uint<CTRL_BITS> s, ap_uint<NUM_BITS>* dout);
ap_int<NUM_BITS> barrel_shift_al(ap_int<NUM_BITS> din, ap_uint<CTRL_BITS> s);
ap_int<NUM_BITS> barrel_shift_ar(ap_int<NUM_BITS> din, ap_uint<CTRL_BITS> s);
ap_uint<NUM_BITS> barrel_shift_rr(ap_uint<NUM_BITS> din, ap_uint<CTRL_BITS> s);
ap_uint<NUM_BITS> barrel_shift_ll(ap_uint<NUM_BITS> din, ap_uint<CTRL_BITS> s);
ap_uint<NUM_BITS> barrel_shift_lr(ap_uint<NUM_BITS> din, ap_uint<CTRL_BITS> s);
ap_uint<NUM_BITS> barrel_shift_lr_const(ap_uint<NUM_BITS> din, ap_uint<CTRL_BITS> s);
ap_uint<NUM_BITS> shift_mask_dynamic(ap_uint<NUM_BITS> din);
ap_uint<NUM_BITS> shift_mask_static(ap_uint<NUM_BITS> din);
ap_uint<NUM_BITS> bi_shift(ap_uint<NUM_BITS> din, ap_int<CTRL_BITS> s);

#endif
