int countValidSelections(int* nums, int numsSize) {
    int ans=0, left=0, right=0;
    for(int i=0;i<numsSize;i++){
        right += nums[i];
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0){
            if(left-right==0) ans+=2;
            else if(left-right==1 || right-left==1) ans++;
        }
        else{
            left += nums[i];
            right -= nums[i];
        }
    }
    return ans;
}