#include<stdio.h>

typedef unsigned float_bits;

float_bits float_denorm_zero(float_bits f) {
    /* Decompose bit representation into parts */
    unsigned sign = f>>31;
    unsigned exp = f>>23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if (exp == 0) {
        /* Denormalized. Set fraction to 0 */
        frac = 0;
    }
    /* Reassemble bits */
    return (sign << 31) | (exp << 23) | frac;
}

float_bits float_negate(float_bits f){
    /* Decompose bit representation into parts */
    unsigned sign = f>>31;
    unsigned exp = f>>23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int isNan = (exp == 0xff) && (frac != 0);
    if(isNan){
        return f;
    }
    return ~sign | exp<<23 | frac;
}


