int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int *sumx=calloc(*gridColSize, sizeof(int));
    int *sumy=calloc(*gridColSize, sizeof(int));
    int ans=0;
    for(int i=0;i<gridSize;i++){
        int x=0, y=0;
        for(int j=0;j<(*gridColSize);j++){
            if(grid[i][j]=='X'){
                x++;
            }
            else if(grid[i][j]=='Y'){
                y++;
            }
            sumx[j]+=x;
            sumy[j]+=y;
            if(sumx[j]>0 && sumx[j]==sumy[j]){
                ans++;
            }
        }
    }
    return ans;
}