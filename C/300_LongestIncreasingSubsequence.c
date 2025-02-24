int lengthOfLIS(int* nums, int numsSize) {
    // Dynamic Programming
    int *sublen = malloc(sizeof(int)*numsSize); // store the longest increasing subsequence of nums[0...i]
    int ans = 0;

    for(int end=0;end<numsSize;end++){
        sublen[end] = 1;
        for(int start=0;start<end;start++){
            if(nums[end]>nums[start] && sublen[end]<sublen[start]+1){
                sublen[end] = sublen[start]+1;
            }
        }
    }
    for(int i=0;i<numsSize;i++){
        ans = fmax(ans, sublen[i]);
    }
    return ans;
}