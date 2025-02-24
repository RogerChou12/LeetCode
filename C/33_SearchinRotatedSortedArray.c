int search(int* nums, int numsSize, int target) {
    int left=0, right=numsSize-1;

    while(left <= right){
        int mid=(left+right)/2;
        if(nums[mid]==target) return mid; // find target and return index of target
        // Check if the left half (nums[left] to nums[mid]) is sorted
        if(nums[left]<=nums[mid]){
            // target lies within the sorted left half
            if(target>=nums[left] && target<=nums[mid]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        else{
            // Check if the right half (nums[mid] to nums[right]) is sorted
            if(target>=nums[mid] && target<=nums[right]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
    }
    return -1;
}