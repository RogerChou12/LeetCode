/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
    int xor=0, max=(1<<maximumBit)-1;
    int *ans = malloc(sizeof(int)*numsSize);

    for(int i=0;i<numsSize;i++){
        xor ^= nums[i];
        ans[numsSize-1-i] = xor ^ max;
    }
    
    (*returnSize) = numsSize;
    return ans;
}