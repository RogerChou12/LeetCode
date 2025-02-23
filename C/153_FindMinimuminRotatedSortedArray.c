int findMin(int* nums, int numsSize) {
    int left=0, right=numsSize-1;

    while(left < right){
        int mid=(left+right)/2;
        if(nums[mid]>nums[right]){
            // minimum is in right of middle value
            left=mid+1;
        }
        else{
            // minimum is in right of middle value
            right=mid;
        }
    }
    return nums[left];
}