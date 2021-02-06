// 写一个 C 表达式，在下列描述的条件下产生 1, 而在其他情况下得到 0 。假设 x 是 l.吐类型。
// A. X 的任何位都等千 1 。
// B. X 的任何位都等千 0 。
// C. X 的最低有效字节中的位都等于 1 。
// D. X 的最高有效字节中的位都等千 0 。
// 代码应该遵循位级整数编码规则，另外还有一个限制，你不能使用相等（＝＝）和不相等(! =)
// 测试。

#include<stdio.h>

typedef unsigned char* byte_pointer;

int A(int x){
    return ! ~x;
}

int B(int x){
    return !x;
}

int C(int x){
    return A(x | ~0xff);
}

int D(int x){
    return B(x & 0xff << ((sizeof(int)-1) << 3) );
}

int slove(int x){
    if(A(x) | B(x) | C(x) | D(x))
        return 1;
    else
        return 0;
}

int main(){
    printf("Positive Result: \n");
    printf("%d\n", slove(~0)); // all 1
    printf("%d\n", slove(0)); // all 0
    printf("%d\n", slove(0x1234ff));
    printf("%d\n", slove(0x1234));
    printf("%d\n", D(0));

    printf("Negtive Result: \n");
    printf("%d\n", B(0x1234ff));
    printf("%d\n", C(0x1234));
    printf("%d\n", D(~0));
    return 0;
}