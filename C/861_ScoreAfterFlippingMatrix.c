int matrixScore(int** grid, int gridSize, int* gridColSize) {
    int ans = gridSize * (1<<(gridColSize[0]-1)); // Assume the bits in the first column are all set bits.

    for(int j=1;j<gridColSize[0];j++){
        int ones = 0;
        for(int i=0;i<gridSize;i++){
            if(grid[i][j] == grid[i][0]){
                ones++;
            }
        }
        ans += fmax(ones, gridSize-ones) * (1<<gridColSize[0]-1-j);
    }
    return ans;
}