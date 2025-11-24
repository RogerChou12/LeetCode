/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdbool.h>

 bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    bool *ans=malloc(sizeof(bool)*numsSize);
    int remain=0;
    for(int i=0;i<numsSize;i++){
        remain=((remain<<1)|nums[i])%5;
        ans[i]=(remain==0);
    }
    (*returnSize)=numsSize;
    return ans;
}