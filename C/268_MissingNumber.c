int missingNumber(int* nums, int numsSize) {
    int total=(0+numsSize)*(1+numsSize)/2;
    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum += nums[i];
    }
    return total-sum;
}