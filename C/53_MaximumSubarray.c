int maxSubArray(int* nums, int numsSize) {
    int sum=0, max_sum=nums[0];

    for(int i=0;i<numsSize;i++){
        sum += nums[i];
        if(sum > max_sum) max_sum=sum;
        if(sum < 0) sum=0;
    }
    return max_sum;
}