int dfs(int x, int y, int d, int turn, int target, int** grid, int gridSize, int* gridColSize, int directions[4][2], int longest[gridSize][gridColSize[0]][4][2]){
    int nx=x+directions[d][0], ny=y+directions[d][1];
    if(nx<0 || nx>=gridSize || ny<0 || ny>=gridColSize[0] || grid[nx][ny]!=target){
        return 0;
    }
    if(longest[nx][ny][d][turn]!=-1){
        return longest[nx][ny][d][turn];
    }
    int max_length=dfs(nx, ny, d, turn, 2-target, grid, gridSize, gridColSize, directions, longest);
    if(turn==1){
        max_length=fmax(max_length, dfs(nx, ny, (d+1)%4, 0, 2-target, grid, gridSize, gridColSize, directions, longest));
    }
    longest[nx][ny][d][turn]=max_length+1;
    return max_length+1;
}
int lenOfVDiagonal(int** grid, int gridSize, int* gridColSize) {
    int ans=0;
    int directions[4][2]={{1,1}, {1,-1}, {-1,-1}, {-1,1}};
    int longest[gridSize][gridColSize[0]][4][2];
    memset(longest, -1, sizeof(longest));

    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if(grid[i][j]==1){
                for(int d=0;d<4;d++){
                    ans=fmax(ans, 1+dfs(i, j, d, 1, 2, grid, gridSize, gridColSize, directions, longest));
                }
            }
        }
    }
    return ans;
}