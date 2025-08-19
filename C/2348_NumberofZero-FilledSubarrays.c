long long zeroFilledSubarray(int* nums, int numsSize) {
    long long counter=0, ans=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0){
            counter++;
        }
        else{
            counter=0;
        }
        ans += counter;
    }
    return ans;
}