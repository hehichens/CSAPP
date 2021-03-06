#include<stdio.h>
#include<assert.h>

int divide_power2(int x, int k){
    int bias;
    (x >> 31) && (bias = (k << 1) - 1); 
    return (x + bias) >> k;
}

int main(){
    int x = 0x80000007;
    assert(divide_power2(x, 1) == x / 2);
    assert(divide_power2(x, 2) == x / 4);
    return 0;
}
