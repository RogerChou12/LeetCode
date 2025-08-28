/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp_decrease(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}
int cmp_increase(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int** sortMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    (*returnSize)=gridSize;
    (*returnColumnSizes)=gridColSize;
    // Bottom-left triangle
    for(int i=0;i<gridSize;i++){
        int *temp=malloc(sizeof(int)*(gridSize));
        int idx=0;
        for(int j=0;(i+j)<gridSize;j++){
            temp[idx++]=grid[i+j][j];
        }
        qsort(temp, idx, sizeof(int), cmp_decrease);
        // Put elements bask to 'grid'
        for(int j=0;(i+j)<gridSize;j++){
            grid[i+j][j]=temp[j];
        }
    }
    // Top-right triangle
    for(int j=1;j<gridSize;j++){
        int *temp=malloc(sizeof(int)*(gridSize));
        int idx=0;
        for(int i=0;(i+j)<gridSize;i++){
            temp[idx++]=grid[i][j+i];
        }
        qsort(temp, idx, sizeof(int), cmp_increase);
        // Put elements bask to 'grid'
        for(int i=0;(i+j)<gridSize;i++){
            grid[i][j+i]=temp[i];
        }
    }
    return grid;
}