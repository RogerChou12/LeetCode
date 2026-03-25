#include<stdbool.h>

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    long long *colsum=calloc(gridColSize[0], sizeof(long long));
    long long *rowsum=calloc(gridSize, sizeof(long long));
    long long total=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            total+=grid[i][j];
            colsum[j]+=grid[i][j];
            rowsum[i]+=grid[i][j];
        }
    }

    if(total%2) return false;
    long long sum=0;
    long long target=total/2;
    for(int i=0;i<gridSize;i++){
        sum+=rowsum[i];
        if(sum==target) return true;
    }
    sum=0;
    for(int j=0;j<gridColSize[0];j++){
        sum+=colsum[j];
        if(sum==target) return true;
    }

    return false;
}