#include<stdbool.h>

bool canJump(int* nums, int numsSize) {
    int furthest=0;
    // keep track the furthest reachable index
    for(int i=0;i<numsSize;i++){
        if(furthest < i) return false;
        furthest = fmax(furthest, i+nums[i]);
    }
    return true;
}