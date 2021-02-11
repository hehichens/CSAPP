#include<stdio.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f){
    unsigned sign = f >> 31;
    unsigned rest = f & 0x7fffffff;
    unsigned exp = f >> 23;
    unsigned frac = f & 0x7fffff;
    int add = (frac&0x3) == 0x3;

    if(exp==0xff){
        return f;
    }
    else if(exp == 0){
        //Denorm
        frac >>= 1;
        farc += add;
    }
    else if(exp == 1){
        rest >>= 1;
        rest += add;
        exp = rest >> 23 & 0xff;
        frac = rest & 0x7fffff;
    }
    else{
        exp -= 1;
    }
    return sign << 31 | exp << 23 | frac;
}
