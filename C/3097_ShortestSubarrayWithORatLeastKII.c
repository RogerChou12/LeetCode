int minimumSubarrayLength(int* nums, int numsSize, int k) {
    int or=0, ans=numsSize+1;
    int *bitcount=calloc(32, sizeof(int));

    for(int i=0, start=0;i<numsSize;i++){
        or |= nums[i];
        for(int bit=0;bit<32;bit++){
            bitcount[bit] += ((nums[i]>>bit) & 1);
        }

        if(or < k){
            continue;
        }
        // Shrink the sliding window
        for(;(start<=i) && (or>=k);start++){
            for(int bit=0;bit<32;bit++){
                bitcount[bit] -= ((nums[start]>>bit) & 1);
                if(bitcount[bit]==0){
                    or &= (~((unsigned int)1<<bit));
                }
            }
            ans = fmin(ans, (i-start+1));
        }
    }
    
    return (ans==numsSize+1)?-1:ans;
}