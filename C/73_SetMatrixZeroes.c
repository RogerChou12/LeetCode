void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    bool firstRow=0, firstCol=0;
    // is there 0 in first row and column
    for(int i=0;i<matrixSize;i++){
        if(matrix[i][0]==0){
            firstCol = 1;
            break;
        }
    }
    for(int i=0;i<matrixColSize[0];i++){
        if(matrix[0][i]==0){
            firstRow = 1;
            break;
        }
    }
    // check the matrix expect row=0, col=0
    for(int i=1;i<matrixSize;i++){
        for(int j=1;j<matrixColSize[i];j++){
            if(matrix[i][j]==0){
                // mark 0
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // set entire row and column to 0's expect row=0, col=0
    for(int i=1;i<matrixSize;i++){
        for(int j=1;j<matrixColSize[i];j++){
            if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j] = 0;
        }
    }
    // set row=0 to 0
    if(firstRow){
        for(int i=0;i<matrixColSize[0];i++) matrix[0][i] = 0;
    }
    // set rcol=0 to 0
    if(firstCol){
        for(int i=0;i<matrixSize;i++) matrix[i][0] = 0;
    }
}