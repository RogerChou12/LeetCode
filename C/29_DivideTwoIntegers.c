#include<limits.h>

int divide(int dividend, int divisor) {
    if(dividend == divisor)  return 1;

    int sign = (dividend<0)^(divisor<0) ? -1:1;
    unsigned int dividend01 = (dividend<0) ? -(long)dividend:(long)dividend;
    unsigned int divisor01 = (divisor<0) ? -(long)divisor:(long)divisor;
    unsigned int ans = 0;
    while(dividend01 >= divisor01){
        int bits=0;
        while(dividend01 > (divisor01<<(bits+1))){
            bits++;
        }
        ans += (1<<bits);
        dividend01 -= (divisor01<<bits);
    }
    if(ans>INT_MAX && sign==1) return INT_MAX;
    return sign*ans;
}