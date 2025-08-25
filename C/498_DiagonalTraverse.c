/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int *ans=malloc(sizeof(int)*(matSize*matColSize[0]));
    int start=0, row=0, col=0, idx=0;

    for(start=0;start<(matSize+matColSize[0]-1);start++){
        if(start<matColSize[0]){
            row=0;
            col=start;
        }
        else{
            row=start-matColSize[0]+1;
            col=matColSize[0]-1;
        }

        int temp[matSize];
        int count=0;
        for(int i=0;i<matSize && row<matSize && col>=0;i++){
            temp[i]=mat[row][col];
            row++;
            col--;
            count++;
        }

        if(start%2){
            for(int j=0;j<count;j++){
                ans[idx++]=temp[j];
            }
        }
        else{
            for(int j=count-1;j>=0;j--){
                ans[idx++]=temp[j];
            }
        }
    }
    (*returnSize)=idx;
    return ans;
}