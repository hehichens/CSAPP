#include<stdio.h>
#include<assert.h>

int lower_one_mask(int n);

int main(){
    int n;
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    assert(lower_one_mask(32) == 0xFFFFFFFF);
    return 0;
}


int lower_one_mask(int n){
    unsigned mask = -1;
    return  mask>> (32-n) ;
}
