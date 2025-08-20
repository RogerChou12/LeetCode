int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    int **dp=malloc(sizeof(int*)*(matrixSize+1));
    for(int i=0;i<matrixSize+1;i++){
        dp[i]=calloc(matrixColSize[0]+1, sizeof(int));
    }
    int ans=0;

    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixColSize[i];j++){
            if(matrix[i][j]==1){
                int min=fmin(dp[i+1][j], dp[i][j+1]);
                min=fmin(min, dp[i][j]);
                dp[i+1][j+1]=min+1;
                ans+=dp[i+1][j+1];
            }
            else{
                dp[i+1][j+1]=0;
            }
        }
    }

    return ans;
}