int cmpInt(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
    qsort(nums, numsSize, sizeof(int), cmpInt);
    int maxVal=nums[numsSize-1];
    int *freq=calloc(maxVal+1, sizeof(int));
    int ans=0;
    for(int i=0;i<numsSize;i++){
        freq[nums[i]]++;
    }
    // Prefix sum array for range queries
    for(int i=1;i<=maxVal;i++){
        freq[i]+=freq[i-1];
    }
    // Calculate how many elements can be transformed to target value
    for(int i=0;i<=maxVal;i++){
        int left=fmax(0, i-k); // Left boundary
        int right=fmin(maxVal, i+k); // Right boundary
        int total=freq[right]-(left?freq[left-1]:0); // Total frequency of elements that can be transformed to 'i'
        int freq_i=freq[i]-(i?freq[i-1]:0);
        ans=fmax(ans, freq_i+fmin(numOperations, total-freq_i));
    }
    return ans;
}