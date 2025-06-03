void backtrack(int* nums, int numsSize, int* count, int index, int curOR, int maxOR){
    if(curOR == maxOR){
        (*count)++;
    }
    for(int i=index;i<numsSize;i++){
        backtrack(nums, numsSize, count, i+1, curOR|nums[i], maxOR);
    }
}

int countMaxOrSubsets(int* nums, int numsSize) {
    int maxOR=0, count=0;
    for(int i=0;i<numsSize;i++){
        maxOR |= nums[i];
    }
    backtrack(nums, numsSize, &count, 0, 0, maxOR);
    return count;
}