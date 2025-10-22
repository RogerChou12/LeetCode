int cmpInt(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
    qsort(nums, numsSize, sizeof(int), cmpInt);
    int ans=0, count=0, left=0, right=0;
    int maxValue=nums[numsSize-1];
    for(int i=0;i<numsSize;i++){
        int value=nums[i];
        int Lvalue=fmax(1, value-k);
        int Rvalue=fmin(maxValue, value+k);
        int freq_value=1;
        for(int j=i+1;j<numsSize && nums[j]==value;j++){
            freq_value++;
            i=j;
        }
        while(left<numsSize && nums[left]<Lvalue) left++;
        right=(right>i)?right:i; // Start r from the last position
        while(right+1<numsSize && nums[right+1]<=Rvalue) right++;
        count=right-left+1;
        ans=fmax(ans, freq_value+fmin(numOperations, count-freq_value));
    }
    // The target value is not present in the original array
    for(left=0, right=0;right<numsSize;right++){
        int Rvalue=nums[right];
        int Lvalue=fmax(1, Rvalue-2*k);
        while(left<right && nums[left]<Lvalue) left++;
        ans=fmax(ans, fmin(right-left+1, numOperations));
    }
    return ans;
}