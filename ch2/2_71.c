#include<stdio.h>
#include<assert.h>

typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum);

int main(){
    assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte(0x00112233, 2) == 0x11);
    return 0;
}

int xbyte(packed_t word, int bytenum){
    int shift_left_val = (3-bytenum)<<3;
    int shift_right_val = 3<<3;
    return (int)word << shift_left_val >> shift_right_val;
}
