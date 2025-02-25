/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    (*returnSize) = matrixSize*matrixColSize[0];
    int *ans = malloc(sizeof(int)*(*returnSize));
    int left=0, right=matrixColSize[0]-1, top=0, bottom=matrixSize-1;
    int ans_id=0;

    while(left<=right && top<=bottom){
        // columns from left to right in a row
        for(int i=left;i<=right;i++){
            ans[ans_id++] = matrix[top][i];
        }
        top++; // move to next row
        // rows from top to bottom in a column
        for(int i=top;i<=bottom;i++){
            ans[ans_id++] = matrix[i][right];
        }
        right--; // move to left column
        // check 'top' and 'bottom
        if(top<=bottom){
            // columns from right to left in a row
            for(int i=right;i>=left;i--){
                ans[ans_id++] = matrix[bottom][i];
            }
            bottom--;
        }
        // check 'left' and 'right'
        if(left<=right){
            // rows from bottom to top in a column
            for(int i=bottom;i>=top;i--){
                ans[ans_id++] = matrix[i][left];
            }
            left++; // move to right column
        }
    }
    return ans;
}