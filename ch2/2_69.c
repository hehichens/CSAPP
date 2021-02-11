#include<stdio.h>
#include<assert.h>

unsigned rotate_left(unsigned x, int n);

int main(){
    unsigned x = 0x12345678;
    assert(rotate_left(x, 4) == 0x23456781);
    assert(rotate_left(x, 20) == 0x67812345);
    return 0;
}

unsigned rotate_left(unsigned x, int n){
    return x << n | x >> (32-n);
}
