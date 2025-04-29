/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int left=0, right=numsSize-1, idx=numsSize-1;
    int *ans = malloc(sizeof(int)*numsSize);

    while(idx >= 0){
        if(pow(nums[left], 2) > pow(nums[right], 2)){
            ans[idx--] = pow(nums[left++], 2);
        }
        else{
            ans[idx--] = pow(nums[right--], 2);
        }
    }

    (*returnSize) = numsSize;
    return ans;
}