int cmpInt(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int minRemoval(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmpInt);
    int remove=numsSize;
    int maxID=0;
    for(int minID=0;minID<numsSize;minID++){
        while(maxID<numsSize && nums[maxID]<=(long long)nums[minID]*k){
            maxID++;
        }
        remove=fmin(remove, numsSize-(maxID-minID));
    }
    return remove;
}