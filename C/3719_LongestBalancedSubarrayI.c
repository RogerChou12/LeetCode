int longestBalanced(int* nums, int numsSize) {
    int ans=0;
    for(int i=0;i<numsSize;i++){
        if(numsSize-i<ans) break;
        int *count=calloc(100001, sizeof(int));
        int odd=0, even=0;
        for(int j=i;j<numsSize;j++){
            count[nums[j]]++;
            if(nums[j]&1){
                if(count[nums[j]]==1){
                    odd++;
                }
            }
            else{
                if(count[nums[j]]==1){
                    even++;
                }
            }

            if(even==odd){
                ans=fmax(ans, (j-i+1));
            }
        }
        free(count);
    }
    return ans;
}