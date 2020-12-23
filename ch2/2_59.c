// 编写一个 C 表达式，它生成一个字，由 x 的最低有效字节和 y 中剩下的字节组成。对千运算数 x
// =Ox89ABCDEF 和 y=Ox76543210, 就得到 Ox765432EF 。

#include<stdio.h>

typedef unsigned char* byte_pointer;

void method_1(int x, int y){
    printf("before: ");
    printf("x=%x, y=%x\n", x, y);
    
    byte_pointer xp = (byte_pointer) &x;
    byte_pointer yp = (byte_pointer) &y;
    yp[0] = xp[0];

    printf("after: ");
    printf("x=%x, y=%x\n", x, y);
}

void method_2(int x, int y){
    int mask = 0xff;
    printf("before: ");
    printf("x=%x, y=%x\n", x, y);

    y = (x & mask) | (y & ~mask);

    printf("after: ");
    printf("x=%x, y=%x\n", x, y);
}

int main(){
    int x = 0x89ABCDEF, y = 0x76543210;
    printf("method 1:\n");
    method_1(x, y);
    printf("=====================\n");
    printf("method 2:\n");
    method_2(x, y);
    return 0;
}