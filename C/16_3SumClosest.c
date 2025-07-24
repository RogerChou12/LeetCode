#include<limits.h>

int cmpInt(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int sum=0, min_diff=INT_MAX, ans=0;
    qsort(nums, numsSize, sizeof(int), cmpInt);

    for(int i=0;i<numsSize;i++){
        int diff=0, left=i+1, right=numsSize-1;

        if((i>0) && (nums[i]==nums[i-1])){
            continue;
        }

        while(left<right){
            int sum=nums[i]+nums[left]+nums[right];
            diff=abs(sum-target);

            if(diff < min_diff){
                min_diff=diff;
                ans=sum;
            }

            if(sum==target){
                return target;
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
    }
    return ans;
}