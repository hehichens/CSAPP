// 将下面的 C 函数代码补充完整。函数 srl 用算术右移（由值 xsra 给出）来完成逻辑右移，后面的其
// 他操作不包括右移或者除法。函数 sra 用逻辑右移（由值 xsrl 给出）来完成算术右移，后面的其他
// 操作不包括右移或者除法。可以通过计算 8*sizeof(int) 来确定数据类型 int 中的位数 w。位移
// 趾 k 的取值范围为 O~w-1 。
// unsigned srl(unsigned x, int k) {
// /• Perform shift arithmetically•/
// unsigned xsra = (int) x»k;
// ····
// ·
// ·}
// int sra(int x, int k) {
// I• Perform shift logically•/
// int xsrl = (unsigned) x»k;


// 逻辑右移就是不考虑符号位，右移一位，左边补零即可。
// 算术右移需要考虑符号位，右移一位，若符号位为1，就在左边补1,；否则，就补0。
// 所以算术右移也可以进行有符号位的除法，右移,n位就等于除2的n次方。

// 例如，8位二进制数11001101分别右移一位。
// 逻辑右移就是[0]1100110
// 算术右移就是[1]1100110

//在C中,左移是逻辑/算术左移(两者完全相同),右移是算术右移,会保持符号位不变
// C语言中，对于移位操作执行的是逻辑左移和算术右移，不过对于无符号类型，所有的移位操作都是逻辑的

# include<stdio.h>
#include <assert.h>

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;

    int w = sizeof(int) << 3;
    int mask = (int) -1 << (w - k);
    return xsra & ~mask;
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;

    int w = sizeof(int) << 3;
    int mask = (int) -1 << (w - k);
    //let mask remain unchanged when the first bit of x is 1, otherwise 0.
    int m = 1 << (w - 1);
    printf("%x\n", mask);
    printf("%x\n", x);
    printf("%x\n", m);
    mask &= ! (x & m) - 1;
    printf("%x\n", mask);
    printf("\n");
    return xsrl | mask;
}

int main(int argc, char* argv[]) {
    unsigned test_unsigned = 0x12345678;
    int test_int = 0x12345678;

    assert(srl(test_unsigned, 4) == test_unsigned >> 4);
    assert(sra(test_int, 4) == test_int >> 4);

    test_unsigned = 0x87654321;
    test_int = 0x87654321;

    assert (srl (test_unsigned, 4) == test_unsigned >> 4);
    assert (sra (test_int, 4) == test_int >> 4);

    return 0;
}