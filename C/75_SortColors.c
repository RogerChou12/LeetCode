void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int one=0, zero=0, two=numsSize-1;

    while(one <= two){
        if(nums[one] > 1){
            swap(&nums[one], &nums[two]);
            two--;
        }
        else if(nums[one] < 1){
            swap(&nums[one], &nums[zero]);
            zero++;
            one++;
        }
        else{
            one++;
        }
    }
}