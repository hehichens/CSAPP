// 写出代码实现如下函数：
// /• Return 1 when any odd bit of x equals 1; 0 otherwise.
// Assume w=32•/
// int any_odd_one(unsigned x);
// 函数应该遵循位级整数编码规则，不过你可以假设数据类型 int 有 w=32 位。

//两个!是为了把 非0值 转换成1，而0值还是0

#include<stdio.h>
#include<assert.h>

int any_odd_one(unsigned x){
    return 0xAAAAAAAA & x;
}

int main(){
    assert(any_odd_one(0x2));
    assert(!any_odd_one(0x4));
    return 0;
}