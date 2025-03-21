void swap(int* a, int* b){
    int temp = *a;
    *a = * b;
    *b = temp;
}

void reverse(int* nums, int start, int end){
    while(start < end){
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int increase = numsSize-1;
    // Find the decreasing element from the rightmost element
    while(increase>0 && nums[increase]<=nums[increase-1]){
        increase--;
    }

    if(increase > 0){
        int right = numsSize-1;
        // Find the smallest element greater than nums[increase-1] in the suffix
        while(right>(increase-1) && nums[right]<=nums[increase-1]){
            right--;
        }
        swap(&nums[right], &nums[increase-1]);
    }
    reverse(nums, increase, numsSize-1);
}