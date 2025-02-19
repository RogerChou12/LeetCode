bool containsDuplicate(int* nums, int numsSize) {
    int min=nums[0], max=nums[0];

    for(int i=0;i<numsSize;i++){
        if(nums[i]<min) min=nums[i];
        if(nums[i]>max) max=nums[i];
    }

    int range=max-min+1;
    int* hashTable=calloc(range, sizeof(int));
    for(int i=0;i<numsSize;i++){
        hashTable[nums[i]-min]++;
        if(hashTable[nums[i]-min]>1){
            return true;
        }
    }
    return false;
}