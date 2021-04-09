#ifndef __LUT__
#define __LUT__
#include <ap_fixed.h>
#include "log2ceil.h"

#define WIDTH 8
#define NUM_REGS 16
#define ADDR_WIDTH LOG2_CEIL<NUM_REGS>::val
ap_fixed<WIDTH,2> lut(ap_uint<ADDR_WIDTH> i);

#endif
