#include<stdio.h>
#include<assert.h>

int signed_high_prod(int x, int y);
unsigned int unsigned_high_prod(unsigned x, unsigned y);
unsigned prod(unsigned x, unsigned y);

int main(){
    unsigned x = 0x12345678;
    unsigned y = 0x87654321;
    assert(prod(x, y) == unsigned_high_prod(x, y));
    return 0;
}


int signed_high_prod(int x, int y){
    return (long) x * y >> 32;
}


unsigned int unsigned_high_prod(unsigned x, unsigned y){
    int sx = x >> 31;
    int sy = y >> 31;
    return signed_high_prod(x, y) + sx * y + sy * x;
}

unsigned prod(unsigned x, unsigned y){
    return (long) x * y >> 32;
}


