int minimumDistance(int* nums, int numsSize) {
    int ans=numsSize+1;
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]==nums[j]){
                for(int k=j+1;k<numsSize;k++){
                    if(nums[j]==nums[k]){
                        if(k-i<ans){
                            ans=k-i;
                        }
                        break;
                    }
                }
            }
        }
    }
    return ans==numsSize+1?-1:2*ans;
}