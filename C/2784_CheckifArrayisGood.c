#include<stdbool.h>

int cmpInt(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

bool isGood(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpInt);
    if(numsSize<nums[numsSize-1]+1) return false;
    if(nums[numsSize-1]!=nums[numsSize-2]) return false;
    for(int i=0;i<numsSize-1;i++){
        if(nums[i]!=i+1) return false;
    }
    return true;
}