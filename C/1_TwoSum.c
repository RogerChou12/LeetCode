/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>

int cmpInt(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *copy=malloc(sizeof(int)*numsSize);
    memcpy(copy, nums, numsSize*sizeof(int));
    qsort(copy, numsSize,sizeof(int), cmpInt);
    int *values=malloc(sizeof(int)*2);
    int *ans=malloc(sizeof(int)*2);
    int left=0, right=numsSize-1;
    (*returnSize)=0;

    while(left < right){
        int sum=copy[left]+copy[right];
        printf("left=%d, right=%d\n", left, right);
        if(sum > target) right--;
        else if(sum < target) left++;
        else{
            values[0]=copy[left];
            values[1]=copy[right];
            (*returnSize)=2;
            break;
        }
    }

    if((*returnSize)==2){
        int count=0;
        for(int i=0;i<numsSize;i++){
            if(nums[i]==values[0] || nums[i]==values[1]){
                ans[count++]=i;
            }
        }
        return ans;
    }
    return NULL;
}