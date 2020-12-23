#include<stdio.h>

int main(){
    int x = 1, y = 1;
    if(~(x^y))
        printf("x == y\n");
    else
        printf("x != y\n");
    return 0;
}