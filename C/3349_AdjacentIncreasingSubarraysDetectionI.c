#include<stdbool.h>

bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    int curIncrease=1, preIncrease=0;
    for(int i=1;i<numsSize;i++){
        if(nums[i]>nums[i-1]){
            curIncrease++;
        }
        else{
            preIncrease=curIncrease;
            curIncrease=1;
        }
        if(fmax(curIncrease>>1, fmin(preIncrease, curIncrease))>=k){
            return true;
        }
    }
    return false;
}