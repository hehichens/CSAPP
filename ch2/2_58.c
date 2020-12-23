// is litte endian

#include<stdio.h>
#include<assert.h>

typedef unsigned char* byte_pointer;

int is_litte_endian(int x){
    byte_pointer start = (byte_pointer) &x; //48 01 00 00 or 00 00 01 48
    printf("%.2x\n", start[0]);
    if (start[0] == 0x48){
        return 1;
    }
    return 0;
}

int main(){
    int num = 328;
    if(is_litte_endian(num)){
        printf("Yes!\n");
    }
    else{
        printf("No!\n");
    }
    return 0;
}