#include<stdbool.h>

bool binarySearch(int *nums, int numsSize, int target){
    int left=0, right=numsSize-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]>target){
            right=mid-1;
        }
        else if(nums[mid]<target){
            left=mid+1;
        }
        else{
            return true;
        }
    }
    return false;
}

int arithmeticTriplets(int* nums, int numsSize, int diff) {
    int ans=0;
    for(int i=0;i<numsSize;i++){
        if(binarySearch(nums, numsSize, nums[i]+diff) && binarySearch(nums, numsSize, nums[i]+2*diff)){
            ans++;
        }
    }
    return ans;
}