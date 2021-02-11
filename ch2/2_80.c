#include<stdio.h>
#include<assert.h>

int patternA(int k){
    return -1 << k;
}

int patternB(int k, int j){
    return ~(-1 << k) << j;
}

int main(){
    assert(patternA(8) == 0xFFFFFF00);
    assert(patternB(16, 8) == 0x00FFFF00);
    return 0;
}
