#include<stdbool.h>

int maximumUniqueSubarray(int* nums, int numsSize) {
    int left=0, right=0, sum=0, maxSum=0;
    bool seen[10001]={false};

    for(right=0;right<numsSize;right++){
        // Remove duplicates
        while(seen[nums[right]]){
            sum -= nums[left];
            seen[nums[left]]=false;
            left++;
        }
        seen[nums[right]]=true;
        sum += nums[right];
        maxSum=fmax(maxSum, sum);
    }
    return maxSum;
}