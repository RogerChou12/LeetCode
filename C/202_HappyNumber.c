#include<stdbool.h>

int SumOfSquare(int n){
    int sum=0;
    while(n>0){
        sum += (n%10)*(n%10);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow=SumOfSquare(n);
    int fast=SumOfSquare(SumOfSquare(n));

    while(fast!=1 && slow!=fast){
        slow = SumOfSquare(slow);
        fast = SumOfSquare(SumOfSquare(fast));
        
    }

    return fast==1;
}