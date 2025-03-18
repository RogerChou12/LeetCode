/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *ans = malloc(sizeof(int)*numsSize);
    ans[0] = 1;
    // prefix product
    for(int i=1;i<numsSize;i++){
        ans[i] = ans[i-1]*nums[i-1];
    }
    // suffix product
    int suffix = 1;
    for(int i=numsSize-1;i>=0;i--){
        ans[i] *= suffix;
        suffix *= nums[i];
    }

    (*returnSize) = numsSize;
    return ans;
}