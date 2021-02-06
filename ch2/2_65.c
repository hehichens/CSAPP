/*思路--对半消除，每日同时消除两个1并把结果往后推
例子:x =  0x1000 1011
1. x ^= x >> 4; // 高4位1000 与 低四位 1011 做与或运算，同时为1会被置为零
                // x = 1000 0011
2. x ^= x >> 2; // x = 1000 0011
3. x ^= x >> 1; // x = 1000 0000
4. return x & 1; // 0 & 1 => 0;
*/


#include<stdio.h>

int odd_ones(unsigned x);

int main(){
    int x;
    scanf("%d", &x);
    if(odd_ones(x)){
        printf("Yes!\n");
    }
    else{
        printf("No!\n");
    }
    return 0;
}

int odd_ones(unsigned x){
    x ^= x>>16;
    x ^= x>>8;
    x ^= x>>4;
    x ^= x>>2;
    x ^= x>>1;
    return x & 0x1;
}
