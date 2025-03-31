void moveZeroes(int* nums, int numsSize) {
    int zeros=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0) zeros++;
        else if(zeros>0){
            // There are zeros before a non-zero element
            int temp = nums[i];
            nums[i] = 0;
            nums[i-zeros] = temp; // Move the non-zero value forward
        }
    }
}