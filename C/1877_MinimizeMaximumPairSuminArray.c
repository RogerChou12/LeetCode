int cmpInt(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int minPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmpInt);
    int max=0;
    for(int i=0;i<numsSize/2;i++){
        int sum = nums[i]+nums[numsSize-1-i];
        if(sum > max){
            max = sum;
        }
    }
    return max;
}