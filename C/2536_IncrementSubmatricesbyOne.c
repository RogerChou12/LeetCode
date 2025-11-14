/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** rangeAddQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize, int** returnColumnSizes) {
    int **ans=malloc(sizeof(int*)*n);
    int *col=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        ans[i]=calloc(n, sizeof(int));
        col[i]=n;
    }
    int **diff = malloc((n+1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        diff[i] = calloc(n+1, sizeof(int));
    }
    for(int i=0;i<queriesSize;i++){
        int row1=queries[i][0];
        int col1=queries[i][1];
        int row2=queries[i][2];
        int col2=queries[i][3];
        diff[row1][col1]+=1;
        diff[row1][col2+1]-=1;
        diff[row2+1][col1]-=1;
        diff[row2+1][col2+1]+=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int above=(i==0)?0:ans[i-1][j];
            int left=(j==0)?0:ans[i][j-1];
            int diagonal=(i==0||j==0)?0:ans[i-1][j-1];
            ans[i][j]=diff[i][j]+above+left-diagonal;
        }
    }

    for (int i = 0; i <= n; i++) {
        free(diff[i]);
    }
    free(diff);
    (*returnSize)=n;
    (*returnColumnSizes)=col;
    return ans;
}