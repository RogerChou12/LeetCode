int cmpInt(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int findFinalValue(int* nums, int numsSize, int original) {
    qsort(nums, numsSize, sizeof(int), cmpInt);
    for(int i=0;i<numsSize;i++){
        if(nums[i]==original){
            original=original<<1;
        }
    }
    return original;
}