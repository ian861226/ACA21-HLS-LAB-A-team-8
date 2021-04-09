#ifndef __LOG2CEIL__
#define __LOG2CEIL__

template<int N_VAL>
struct LOG2_CEIL{
    enum {
        val = N_VAL <= 1 ? 1: N_VAL <= 2 ? 1 : N_VAL <= 4 ? 2 :
        N_VAL <= 8 ? 3 : N_VAL <= 16 ? 4 : N_VAL <= 32 ? 5 :
        N_VAL <= 64 ? 6 : N_VAL <= 128 ? 7 : N_VAL <= 256 ? 8 :
        N_VAL <= 512 ? 9 : N_VAL <= 1024 ? 10 : N_VAL <= 2048 ? 11 :
        N_VAL <= 4096 ? 12 : N_VAL <= 8192 ? 13 : N_VAL <= 16384 ? 14 :
        N_VAL <= 32768 ? 15 : N_VAL <= 65536 ? 16 : 32
    };
};

#endif
