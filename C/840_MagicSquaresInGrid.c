#include<stdbool.h>

bool isMagic(int** grid, int row, int col){
    int  *seen=calloc(10, sizeof(int));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int x=grid[row+i][col+j];
            if(x<1 || x>9){
                return false;
            }
            if(seen[x]){
                return false;
            }
            seen[x]=1;
        }
    }
    int dia1=grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2];
    int dia2=grid[row][col+2]+grid[row+1][col+1]+grid[row+2][col];
    if(dia1 != dia2) return false;
    for(int i=0;i<3;i++){
        int rowSum=0, colSum=0;
        for(int j=0;j<3;j++){
            rowSum+=grid[row+i][col+j];
            colSum+=grid[row+j][col+i];
        }
        if(rowSum != dia1) return false;
        if(colSum != dia1) return false;
    }
    return true;
}

int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
    int ans=0;
    for(int i=0;i<gridSize-2;i++){
        for(int j=0;j<gridColSize[i]-2;j++){
            if(isMagic(grid, i, j)){
                ans++;
            }
        }
    }
    return ans;
}