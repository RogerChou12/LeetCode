int cmpInt(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int triangleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpInt);
    int tri3=numsSize-1, count=0;
    for(tri3=numsSize-1;tri3>1;tri3--){
        int tri1=0, tri2=tri3-1;
        while(tri1 < tri2){
            if(nums[tri1]+nums[tri2] > nums[tri3]){
                count += (tri2-tri1);
                tri2--;
            }
            else{
                tri1++;
            }
        }
    }
    return count;
}