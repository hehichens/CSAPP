#include<stdio.h>

void inplace_swap(int *X, int *Y) {
    *Y = *X ^ *Y; //I* Step 1 *I
    *X = *X ^ *Y; //I* Step 2 *I
    *Y = *X ^ *Y; //I* Step 3 *I
}

/* first <= last --> first < last */
void reverse_array(int a[], int cnt) {
    int first, last;
    for (first= 0, last= cnt-1; first < last; first++,last--)
        inplace_swap(&a[first], &a[last]);
}

int main(){
    int a[] = {1, 2, 3, 4, 5};
    reverse_array(a, 5);
    for (int i = 0; i < 5; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}