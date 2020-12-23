#include<stdio.h>

void inplace_swap(int *X, int *Y) {
    *Y = *X ^ *Y; //I* Step 1 *I
    *X = *X ^ *Y; //I* Step 2 *I
    *Y = *X ^ *Y; //I* Step 3 *I
}

int main(){
    int x = 10;
    int y = 11;
    printf("%d, %d\n", x, y);
    printf("after change:\n");
    inplace_swap(&x, &y);
    printf("%d, %d\n", x, y);
    return 0;
}