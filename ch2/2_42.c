#include<stdio.h>

float div16(int x){
    // compute the bias to be either 0(x >= 0) or 15( x < 0)
    int bias = (x >> 31) & 0xf;
    return (x + bias) >> 4;
}

int main(){
    int x = -15;
    printf("%.2f\n", div16(x));
    return 0;
}