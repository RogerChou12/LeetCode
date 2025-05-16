/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void createSubset(int **ans, int *subset, int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int idx, int cur_sub){
    // Already considered all elements in 'nums'
    if(idx == numsSize){
        ans[(*returnSize)] = malloc(sizeof(int)*cur_sub);
        for(int i=0;i<cur_sub;i++){
            ans[(*returnSize)][i] = subset[i];
        }
        (*returnColumnSizes)[(*returnSize)] = cur_sub;
        (*returnSize)++;
        return;
    }
    // Include nums[idx] in the current subset
    subset[cur_sub] = nums[idx];
    createSubset(ans, subset, nums, numsSize, returnSize, returnColumnSizes, idx+1, cur_sub+1); 
    // Do NOT include nums[idx] in the subset
    createSubset(ans, subset, nums, numsSize, returnSize, returnColumnSizes, idx+1, cur_sub); 
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int sublen = 1<<numsSize;
    (*returnSize) = 0;
    (*returnColumnSizes) = calloc(sublen, sizeof(int));
    int **ans = malloc(sizeof(int*)*sublen);
    int *subset = malloc(sizeof(int)*numsSize); // Temporary array to build individual subsets (max size is numsSize)

    createSubset(ans, subset, nums, numsSize, returnSize, returnColumnSizes, 0, 0); // Last 2 elements are [Current index in nums being considered] and [current length of subset]

    return ans;
}