/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestSubarrays(int* nums, int numsSize, int* returnSize) {
    int *ans=malloc(sizeof(int)*numsSize);
    int *bitPosition=calloc(31, sizeof(int));
    // memset(bitPosition, -1, 31*sizeof(int));

    for(int start=numsSize-1;start>=0;start--){
        int end=start;
        for(int bit=0;bit<31;bit++){
            if(nums[start]&(1<<bit)){
                bitPosition[bit]=start;
            }
            else{
                if(bitPosition[bit]>end){
                    end=bitPosition[bit];
                }
            }
        }
        ans[start]=end-start+1;
    }

    *(returnSize)=numsSize;
    return ans;
}