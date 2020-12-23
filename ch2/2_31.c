#include<stdio.h>

int tadd_ok(int x, int y){
    int sum = x + y;
    return (sum - x == y) && (sum - y == x);
}

int main(){
    int x = 10, y = 2147483647;
    printf("x + y = %d\n", x + y);
    printf("%d\n", tadd_ok(x, y));
    return 0;
}