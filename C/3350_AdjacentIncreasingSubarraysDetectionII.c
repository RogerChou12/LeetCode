int maxIncreasingSubarrays(int* nums, int numsSize) {
    int cur=1, prev=0, max_len=0;
    for(int i=1;i<numsSize;i++){
        if(nums[i]>nums[i-1]){
            cur++;
        }
        else{
            prev=cur;
            cur=1;
        }
        int len=fmax(cur>>1, fmin(prev, cur));
        if(len>max_len){
            max_len=len;
        }
    }
    return max_len;
}