#include<stdio.h>
#include<assert.h>

int Tmax = 0x7fffffff;
int Tmin = 0x80000000;

int saturating_add(int x, int y);

int main(){
    assert(Tmax == saturating_add(Tmax, 0x123));
    assert(Tmin == saturating_add(Tmin, -0x123));
    assert(0x123+0x321 == saturating_add(0x321, 0x123));
    return 0;
}


int saturating_add(int x, int y){
    int sum = x + y;
    int s = Tmin;

    int pos_over = !(x & s) && !(y & s) && (sum & s);
    int neg_over = (x & s) && (y & s) && !(sum & s);

    (pos_over && (sum = Tmax) || neg_over && (sum = Tmin));
    return sum;
}
