#include<stdio.h>
#include<stdlib.h>

int floatFloat2Int(unsigned uf);
void showNum(int x);

int main(){
    int x=0x40000001;
    int y=0xa0;
    showNum(y-127);
    // scanf("%x", &x);
    // printf("%d\n", floatFloat2Int(x));
    // showNum(x);
    return 0;
}

int floatFloat2Int(unsigned uf) {
  // Get sign, exponent and fraction
  int sign = uf & 0x80000000;
  int result = 0;
  int exp = (uf & 0x7f800000) >> 23;
  int frac = uf & 0x7fffff;
  int bias = 0x7F; // 2 to (8 - 1) - 1; 127
  int e = 0;

  // Determine whether uf is NaN or infinite
  showNum(uf);
  if(exp  == 0xff)
    return 0x80000000u;
  
  // If uf is 0 or denorm or norm with exp less than bias - round to 0
  if((exp < bias) || !(uf << 1)) 
    return 0;
  
  e = exp - bias;
  showNum(e);

  // If E is great than 31, the representation of integer will overflow
  if (e >= 31)
    return 0x80000000u;
  
  // Add back 1 in the norm case
  frac = frac | 0x800000;
  showNum(frac);

  if(e < 23)
    result = frac >> (23 - e); // If e is less than 23, do right shift
  else
    result = frac << (e - 23); // If e is equal or great than 23, do left shift

  if (sign < 0)
    return -result;
  else
    return result;
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