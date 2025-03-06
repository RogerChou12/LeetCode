void island(char** grid, int gridSize, int* gridColSize, int x, int y){
    if(x<0 || x>=gridSize || y<0 || y>=gridColSize[x]) return;
    if(grid[x][y] != '1') return;
    
    grid[x][y] = 'v';
    island(grid, gridSize, gridColSize, x+1, y);
    island(grid, gridSize, gridColSize, x-1, y);
    island(grid, gridSize, gridColSize, x, y+1);
    island(grid, gridSize, gridColSize, x, y-1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int ans = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if(grid[i][j] == '1'){
                island(grid, gridSize, gridColSize, i, j);
                ans++;
            }
        }
    }
    return ans;
}