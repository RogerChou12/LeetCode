int repeatedNTimes(int* nums, int numsSize) {
    int *check=calloc(10001, sizeof(int));
    for(int i=0;i<numsSize;i++){
        if(check[nums[i]]>0){
            return nums[i];
        }
        check[nums[i]]++;
    }
    return -1;
}