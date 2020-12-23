// 写一个 C 表达式，在下列描述的条件下产生 1, 而在其他情况下得到 0 。假设 x 是 l.吐类型。
// A. X 的任何位都等千 1 。
// B. X 的任何位都等千 0 。
// C. X 的最低有效字节中的位都等于 1 。
// D. X 的最高有效字节中的位都等千 0 。
// 代码应该遵循位级整数编码规则，另外还有一个限制，你不能使用相等（＝＝）和不相等(! =)
// 测试。

#include<stdio.h>

typedef unsigned char* byte_pointer;

/*method 1*/
int method_1(int x){
    int mask_1 = 0;
    int mask_2 = 0;
    int mask_3 = 0xff;
    int mask_4 = 0xff;

    int case_1 = x ^ mask_1;
    int case_2 = x ^ ~mask_2;
    int case_3 = x ^ ~mask_3;
    int case_4 = x ^ mask_4;
    
    if(case_1 | case_2 | case_3 | case_4)
        return 1;
    else
        return 0;
}

int main(){
    printf("method 1: \n");
    printf("%x\n", method_1(0xffffff));
    printf("%x\n", method_1(0x0));
    printf("%x\n", method_1(0x1234ff));
    printf("%x\n", method_1(0x1234));
    printf("%x\n", method_1(0x12340f));
    return 0;
}