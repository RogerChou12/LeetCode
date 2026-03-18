int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int ans=0;
    int *cols=calloc(*gridColSize, sizeof(int));
    for(int i=0;i<gridSize;i++){
        int rows=0;
        for(int j=0;j<gridColSize[0];j++){
            cols[j]+=grid[i][j];
            rows+=cols[j];
            if(rows<=k){
                ans++;
            }
        }
    }
    return ans;
}