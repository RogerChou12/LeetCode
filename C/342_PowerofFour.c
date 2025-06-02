#include<stdbool.h>

bool isPowerOfFour(int n) {
    if(n<=0 || n==2) return false;
    if(n & (n-1)) return false; // Checks if n is a power of 2
    int bits=0;
    while(n){
        n = n>>1;
        bits++;
    }
    return bits%2;
}