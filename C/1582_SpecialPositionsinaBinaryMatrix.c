int numSpecial(int** mat, int matSize, int* matColSize) {
    int *rowCount=calloc(matSize, sizeof(int));
    int *colCount=calloc(matColSize[0], sizeof(int));
    int ans=0;
    for(int i=0;i<matSize;i++){
        for(int j=0;j<matColSize[0];j++){
            if(mat[i][j]==1){
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }
    for(int i=0;i<matSize;i++){
        for(int j=0;j<matColSize[0];j++){
            if(mat[i][j]==1){
                if(rowCount[i]==1 && colCount[j]==1){
                    ans++;
                }
            }
        }
    }
    free(rowCount);
    free(colCount);
    return ans;
}