int findDuplicate(int* nums, int numsSize) {
    int slow=nums[0], fast=nums[nums[0]];
    // find the circle
    while(slow != fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    // find the start of circle
    fast = 0;
    while(fast != slow){
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}
