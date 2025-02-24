void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    // transpose the matrix
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<i;j++){
            int temp=matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // swap the columns
    for(int row=0;row<matrixSize;row++){
        for(int col=0;col<(matrixColSize[row]/2);col++){
            int temp=matrix[row][col];
            matrix[row][col] = matrix[row][matrixColSize[row]-1-col];
            matrix[row][matrixColSize[row]-1-col] = temp;
        }
    }
}