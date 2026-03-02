int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int swaps=0;
    int *last1=malloc(sizeof(int)*gridSize);
    for(int i=0;i<gridSize;i++){
        last1[i]=-1;
        for(int j=gridSize-1;j>=0;j--){
            if(grid[i][j]==1){
                last1[i]=j;
                break;
            }
        }
    }
    for(int i=0;i<gridSize;i++){
        int k=-1;
        for(int j=i;j<gridSize;j++){
            if(last1[j]<=i){
                swaps+=j-i;
                k=j;
                break;
            }
        }
        if(k!=-1){
            for(int j=k;j>i;j--){
                int temp=last1[j];
                last1[j]=last1[j-1];
                last1[j-1]=temp;
            }
        }
        else{
            free(last1);
            return -1;
        }
    }
    free(last1);
    return swaps;
}