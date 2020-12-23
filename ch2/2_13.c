#include<stdio.h>

int bis(int x, int m){
    return x | m;
}

int bic(int x, int m){
    return ~(x & m);
}

int bool_or(int x, int y){
    int result = bis(x, y);
    return result;
}

int bool_xor(int x, int y){
    int result = bis(bic(x, y), bic(x, y));
    return result;
}

int main(){
    int x=100, y=111;
    printf("%d\n", bool_or(x, y));
    printf("%d\n", bool_xor(x, y));
    return 0;
}