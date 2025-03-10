int robber(int* nums, int numsSize, int start, int end){
    int prepre=0, pre=0, max=0;
    for(int i=start;i<=end;i++){
        prepre = pre;
        pre = max;
        max = max > (prepre+nums[i]) ? max:prepre+nums[i];
    }
    return max;
}
int rob(int* nums, int numsSize) {
    // all houses are arranged in a circle
    // 0 to n-2
    // 1 to n-1
    if(numsSize==1) return nums[0];
    int startFrom0 = robber(nums, numsSize, 0, numsSize-2);
    int startFrom1 = robber(nums, numsSize, 1, numsSize-1);
    return (startFrom0 > startFrom1) ? startFrom0:startFrom1;
}