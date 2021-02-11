#include<stdio.h>

int leftmost_one(unsigned x);

int main(){
    unsigned int x;
    scanf("%x", &x);
    printf("%x\n", leftmost_one(x));
    return 0;
}

int leftmost_one(unsigned x){
    x |= x>>1;
    x |= x>>2;
    x |= x>>4;
    x |= x>>8;
    x |= x>>16;
    return (x>>1) + (x & 1);
}
