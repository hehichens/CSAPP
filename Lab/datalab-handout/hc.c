#include<stdio.h>
#include<stdlib.h>

int floatFloat2Int(unsigned uf);
void showNum(int x);

int main(int argc, char *argv[]){
  printf("argc = %d\n", argc);
  for(int i = 1; i < argc; ++i){
      printf("argv_%d = %s\n", i, argv[i]);
  }

  return 0;
}


void showNum(int x){
    printf("Dec=%d, Hex=%xH\n", x, x);
    printf("Bin=");
    char s[32];
    int i = 0;
    unsigned int num = x;
    while(num){
        s[i++] = num%2;
        num /= 2;
    }
    for(;i<32;++i){
        s[i] = 0;
    }
    for(i=31;i>=0;--i){
        printf("%d", s[i]);
        if(i%4==0 && i != 0) printf(" ");
    }
    printf("B\n\n");
}