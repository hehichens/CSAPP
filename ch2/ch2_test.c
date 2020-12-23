# include<stdio.h>

int main(){
    unsigned length = 0;
    /* length 为 无符号整数，0-1为模数加法，结果得到Umax， 任何数都小于Umax，因此会无限循环下去 */
    /* i < length */
    for(int i = 0; i <= length-1 && i < 5; ++i)
        printf("length=%u\n", length-1);
    return 0;
}