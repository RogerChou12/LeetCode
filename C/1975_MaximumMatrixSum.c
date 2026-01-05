#include<limits.h>

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    long long total=0;
    int minAbs=INT_MAX;
    int negative=0;
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixColSize[i];j++){
            total+=abs(matrix[i][j]);
            if(matrix[i][j]<0){
                negative++;
            }
            minAbs=(abs(matrix[i][j])<minAbs)?abs(matrix[i][j]):minAbs;
        }
    }
    if(negative%2!=0){
        total-=2*minAbs;
    }
    return total;
}