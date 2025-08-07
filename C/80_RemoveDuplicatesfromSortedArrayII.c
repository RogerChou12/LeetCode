int removeDuplicates(int* nums, int numsSize) {
    int k=1, twice=0;

    for(int i=1;i<numsSize;i++){
        if(nums[i] != nums[i-1]){
            nums[k++]=nums[i];
            twice=0;
        }
        else{
            twice++;
            if(twice<2){
                nums[k++]=nums[i];
            }
        }
    }
    return k;
}