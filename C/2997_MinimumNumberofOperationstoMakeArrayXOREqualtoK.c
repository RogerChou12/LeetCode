int minOperations(int* nums, int numsSize, int k) {
    int xor=0, diff=0, flips=0;
    for(int i=0;i<numsSize;i++){
        xor ^= nums[i];
    }
    diff = xor ^ k;
    while(diff>0){
        flips += diff&1;
        diff >>= 1;
    }
    return flips;
}