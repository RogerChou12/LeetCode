#include<limits.h>

long long maxSubarraySum(int* nums, int numsSize, int k) {
    long long prefix=0, maxSum=LLONG_MIN;
    long long *ksum=malloc(sizeof(long long)*k);
    for(int i=0;i<k;i++){
        ksum[i]=LLONG_MAX/2;
    }
    ksum[k-1]=0; // prefix sum of id=0 is 0
    for(int i=0;i<numsSize;i++){
        prefix+=nums[i];
        if(prefix-ksum[i%k]>maxSum){
            maxSum=prefix-ksum[i%k];
        }
        if(prefix<ksum[i%k]){
            ksum[i%k]=prefix;
        }
    }
    free(ksum);
    return maxSum;
}