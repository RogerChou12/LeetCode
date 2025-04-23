int minFlips(int** grid, int gridSize, int* gridColSize) {
    int row_count=0, col_count=0;

    // Counting mismatches for rows
    for(int i=0;i<gridSize;i++){
        int left=0, right=gridColSize[i]-1;
        while(left < right){
            row_count += grid[i][left++] ^ grid[i][right--];
        }
    }
    // Counting mismatches for rcolumns
    for(int i=0;i<gridColSize[0];i++){
        int left=0, right=gridSize-1;
        while(left < right){
            col_count += grid[left++][i] ^ grid[right--][i];
        }
    }
    return fmin(row_count, col_count);
}