/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdbool.h>

 bool zero(int x){
    while(x>0){
        if(x%10==0){
            return true;
        }
        x /= 10;
    }
    return false;
}
int* getNoZeroIntegers(int n, int* returnSize) {
    int *ans=malloc(sizeof(int)*2);
    for(int a=1;a<n;a++){
        int b=n-a;
        if(!zero(a) && !zero(b)){
            ans[0]=a;
            ans[1]=b;
            (*returnSize)=2;
            return ans;
        }
    }
    (*returnSize)=0;
    return NULL;
}