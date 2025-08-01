/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **result=malloc(sizeof(int*)*numRows);
    int *columns=malloc(sizeof(int)*numRows);

    for(int i=0;i<numRows;i++){
        columns[i]=i+1;
        result[i]=malloc(sizeof(int)*columns[i]);
        int *vector=calloc(columns[i], sizeof(int));
        vector[0]=1;
        vector[i]=1;
        for(int j=1;j<i;j++){
            vector[j]=result[i-1][j-1]+result[i-1][j];
        }
        result[i]=vector;
    }

    (*returnSize)=numRows;
    (*returnColumnSizes)=columns;
    return result;
}