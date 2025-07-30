int longestSubarray(int* nums, int numsSize) {
    int ans=0, max=0, curLength=0;

    for(int i=0;i<numsSize;i++){
        if(nums[i]>max){
            max=nums[i];
            ans=0;
            curLength=0;
        }
        if(nums[i]==max){
            curLength++;
        }
        else{
            curLength=0;
        }
        ans=fmax(ans, curLength);
    }
    return ans;
}