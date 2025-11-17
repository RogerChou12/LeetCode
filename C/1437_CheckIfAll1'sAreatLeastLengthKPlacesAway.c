#include<stdbool.h>

bool kLengthApart(int* nums, int numsSize, int k) {
    int one=0, preOne=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==1){
            if(one>0){
                if(i-preOne-1<k){
                    return false;
                }
            }
            preOne=i;
            one++;
        }
    }
    return true;
}