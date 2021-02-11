#include <stdio.h>
#include <assert.h>

float_bits float_twice(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_NAN = (exp == 0xFF); 
    if (is_NAN) {
        return f;
    }

    if(exp=0){
        frac <<= 1;
    }
    else if(exp = 0xff-1){
        exp = 0xff;
        frac = 0;
    }
    else{
        exp += 1;
    }
    return sign << 31 | exp << 23 | frac;
}
