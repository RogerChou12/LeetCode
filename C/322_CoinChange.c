#include<limits.h>

int cmpInt(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int coinChange(int* coins, int coinsSize, int amount) {
    int* target = malloc(sizeof(int)*(1+amount)); // stores the minimum number of coins required to make the amount i
    target[0] = 0;
    qsort(coins, coinsSize, sizeof(int), cmpInt);

    for(int a=1;a<=amount;a++){
        target[a] = INT_MAX;
        for(int c=0;c<coinsSize;c++){
            int diff=a-coins[c];
            if(diff < 0) break;
            if(target[diff] != INT_MAX){
                target[a] = fmin(target[a], 1+target[diff]);
            }
        }
    }
    return target[amount]==INT_MAX ? -1:target[amount];
}