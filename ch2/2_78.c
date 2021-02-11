#include<stdio.h>
#include<assert.h>

int divide_power2(int x, int k){
    int bias;
    (x >> 31) && (bias = (k << 1) - 1); 
    return (x + bias) >> k;
}

int mul3div4(int x){
    return divide_power2((x << 1) + x, 2);
}

int main(){
    int x = 0x87654321;
    assert(mul3div4(x) == x * 3 / 4);
    return 0;
}
