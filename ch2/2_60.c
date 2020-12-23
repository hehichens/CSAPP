// 假设我们将一个 w 位的字中的字节从 0( 最低位）到 w/8-l( 最高位）编号。写出下面 C 函数的代
// 码，它会返回一个无符号值，其中参数 x 的字节 i 被替换成字节 b:
// unsigned replace_byte (unsigned x, int i, unsigned char b);
// 以下示例，说明了这个函数该如何工作：
// replace_byte(Ox12345678, 2, OxAB) --> Ox12AB5678
// replace_byte(Ox12345678, 0, OxAB) --> Ox123456AB

#include<stdio.h>

typedef unsigned char* byte_pointer;

unsigned replace_byte1 (unsigned x, int i, unsigned char b){
    byte_pointer p = (byte_pointer) &x;
    p[i] = b;
    return x;
}

unsigned replace_byte2 (unsigned x, int i, unsigned char b){
    unsigned mask = 0xff << (i << 3);
    unsigned pos_bype = b << (i << 3);
    return (x & ~mask) | pos_bype;
}

int main(){
    unsigned res = replace_byte2(0x12345678, 2, 0xAB);
    printf("%x\n", res);
    return 0;
}