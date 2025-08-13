#include<stdbool.h>

bool isPowerOfThree(int n) {
    long temp=1;
    while(n>0 && temp<n){
        temp=temp+(temp<<1); // x+2x
    }
    return temp==n;
}