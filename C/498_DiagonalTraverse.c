/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdbool.h>

 int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int *ans=malloc(sizeof(int)*(matSize*matColSize[0]+1));
    bool directionUP=1;
    int row=0, col=0;
    (*returnSize)=0;

    while(row<matSize && col<matColSize[0]){
        int new_row, new_col;
        ans[(*returnSize)++]=mat[row][col];
        if(directionUP){
            new_row=row-1;
            new_col=col+1;
        }
        else{
            new_row=row+1;
            new_col=col-1;
        }
        if(new_row<0 || new_col<0 || new_row==matSize || new_col==matColSize[0]){
            if(directionUP){
                row=(col==matColSize[0]-1)?(row+1):row;
                col=(col<matColSize[0]-1)?(col+1):col;
            }
            else{
                col=(row==matSize-1)?(col+1):col;
                row=(row<matSize-1)?(row+1):row;
            }
            directionUP=!directionUP; // Flip the direction
        }
        else{
            row=new_row;
            col=new_col;
        }
    }
    return ans;
}