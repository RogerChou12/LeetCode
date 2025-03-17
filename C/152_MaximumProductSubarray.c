#include<limits.h>

int maxProduct(int* nums, int numsSize) {
    int max_product=INT_MIN, prefix=1, suffix=1;

    for(int i=0;i<numsSize;i++){
        // product==0 then reset 1
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
        prefix *= nums[i];
        suffix *= nums[numsSize-1-i];
        max_product = fmax(max_product, fmax(prefix, suffix));
    }

    return max_product;
}