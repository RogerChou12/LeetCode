int rob(int* nums, int numsSize) {
    int prepre=0, pre=0, max=0;
    for(int i=0;i<numsSize;i++){
        prepre = pre;
        pre = max;
        max = (prepre+nums[i])>max ? (prepre+nums[i]):max;
    }
    return max;
}