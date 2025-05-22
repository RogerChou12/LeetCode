int findDuplicate(int* nums, int numsSize) {
    for(int i=0;i<numsSize;i++){
        int idx = abs(nums[i]);
        if(nums[idx]<0){
            return idx;
        }
        nums[idx] = -nums[idx]; // Mark visited value
    }
    return numsSize;
}