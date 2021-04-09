#include "lut.h"

ap_fixed<WIDTH,2> lut(ap_uint<ADDR_WIDTH> i) {
  const ap_fixed<WIDTH,2> sin_table[NUM_REGS] = {
    #include "data.inc"
  };
  return sin_table[i];
}
