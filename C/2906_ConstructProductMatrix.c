/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** constructProductMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int **p=malloc(sizeof(int*)*gridSize);
    (*returnSize)=gridSize;
    (*returnColumnSizes)=malloc(sizeof(int)*gridSize);
    for(int i=0;i<gridSize;i++){
        p[i]=malloc(sizeof(int)*gridColSize[i]);
        (*returnColumnSizes)[i]=gridColSize[i];
    }
    const int mod=12345;
    long long suffix=1;
    for(int i=gridSize-1;i>=0;i--){
        for(int j=gridColSize[0]-1;j>=0;j--){
            p[i][j]=suffix%mod;
            suffix=suffix*grid[i][j]%mod;
        }
    }
    long long prefix=1;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            p[i][j]=p[i][j]*prefix%mod;
            prefix=prefix*grid[i][j]%mod;
        }
    }
    return p;
}