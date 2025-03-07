void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    bool firstRow=0, firstCol=0;
    // Check if the first column has a zero
    for(int i=0;i<matrixSize;i++){
        if(matrix[i][0]==0){
            firstCol = 1;
            break;
        }
    }
    // Check if the first row has a zero
    for(int i=0;i<matrixColSize[0];i++){
        if(matrix[0][i]==0){
            firstRow = 1;
            break;
        }
    }
    // Check the rest of the matrix (excluding the first row and column)
    for(int i=1;i<matrixSize;i++){
        for(int j=1;j<matrixColSize[i];j++){
            if(matrix[i][j]==0){
                // Mark the corresponding row and column
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // Set rows and columns to zero based on markers in the first row and column
    for(int i=1;i<matrixSize;i++){
        for(int j=1;j<matrixColSize[i];j++){
            if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j] = 0;
        }
    }
    // set first row to 0
    if(firstRow){
        for(int i=0;i<matrixColSize[0];i++) matrix[0][i] = 0;
    }
    // set first column to 0
    if(firstCol){
        for(int i=0;i<matrixSize;i++) matrix[i][0] = 0;
    }
}