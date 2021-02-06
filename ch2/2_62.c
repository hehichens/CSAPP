// 编写一个函数 int_shifts_are_arithmetic (), 在对 int 类型的数使用算术右移的机器上运行时
// 这个函数生成 1, 而其他情况下生成 0 。你的代码应该可以运行在任何字长的机器上。在几种机器
// 上测试你的代码。

#include<stdio.h>

int int_shifts_are_arithmetic(int x){
    return !(x ^ (x >> 1));
}

int main(){
    int num = ~0; // 0xffffffff
    if(int_shifts_are_arithmetic(num))
        printf("Yes!\n");
    else
        printf("No!\n");
    return 0;
}
