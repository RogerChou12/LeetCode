/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int** ans, int current, int count, int* sum){
    if(target==0){
        ans[(*returnSize)] = malloc(sizeof(int)*count);
        (*returnColumnSizes)[*(returnSize)] = count;
        for(int i=0;i<count;i++){
            ans[(*returnSize)][i] = sum[i];
        }
        (*returnSize)++;
        return;
    }
    if(target<0 || current>=candidatesSize) return;
    // Recursive case 1: Exclude the current element and move to the next
    backtrack(candidates, candidatesSize, target, returnSize, returnColumnSizes, ans, current+1, count, sum);
    // Recursive case 2: Include the current element in the combination
    sum[count] = candidates[current]; // Store current candidate in the 'sum' array
    backtrack(candidates, candidatesSize, target-candidates[current], returnSize, returnColumnSizes, ans, current, count+1, sum);
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int size=150; //the number of unique combinations that sum up to target is less than 150 combinations
    int **ans = malloc(sizeof(int*)*size);
    int *sum = malloc(sizeof(int) * target); // temporarily store each combination during recursion
    (*returnColumnSizes) = malloc(sizeof(int)*size);
    (*returnSize) = 0;

    backtrack(candidates, candidatesSize, target, returnSize, returnColumnSizes, ans, 0, 0, sum);
    free(sum);
    return ans;
}