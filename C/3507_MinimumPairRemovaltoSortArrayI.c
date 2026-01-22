#include<stdbool.h>

int minimumPairRemoval(int* nums, int numsSize) {
    int *next=malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        next[i]=i+1;
    }
    next[numsSize-1]=-1;
    
    int count=0;
    while(numsSize-count>1){
        int curr=0, minID=0;
        int minSum=nums[minID]+nums[next[minID]];
        bool ascending=true;
        while(curr!=-1 && next[curr]!=-1){
            if(nums[curr]>nums[next[curr]]){
                ascending=false;
            }
            int currSum=nums[curr]+nums[next[curr]];
            if(currSum<minSum){
                minSum=currSum;
                minID=curr;
            }
            curr=next[curr];
        }
        if(ascending) break;
        count++;
        next[minID]=next[next[minID]];
        nums[minID]=minSum;
    }
    free(next);
    return count;
}