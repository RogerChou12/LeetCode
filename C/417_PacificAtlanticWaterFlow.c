/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int** heights, int heightsSize, int* heightsColSize, bool** visited, int row, int col){
    if(visited[row][col]) return;
    visited[row][col] = true;
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    for(int d=0;d<4;d++){
        int row1=row+dir[d][0];
        int col1=col+dir[d][1];
        if(row1>=0 && row1<heightsSize && col1>=0 && col1<heightsColSize[0] && heights[row1][col1]>=heights[row][col]){
            dfs(heights, heightsSize, heightsColSize, visited, row1, col1);
        }
    }
}
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    if(heightsSize==0 || *heightsColSize==0){
        (*returnSize) = 0;
        return NULL;
    }
    bool **pacific=malloc(sizeof(bool*)*heightsSize); //visited the cells connected to pacific ocean
    bool **atlantic=malloc(sizeof(bool*)*heightsSize); //visited the cells connected to altantic ocean
    for(int i=0;i<heightsSize;i++){
        pacific[i] = calloc(heightsColSize[i], sizeof(bool));
        atlantic[i] = calloc(heightsColSize[i], sizeof(bool));
    }
    // perform dfs from all edge cells (ocean-connected cells)
    for(int i=0;i<heightsSize;i++){
        dfs(heights, heightsSize, heightsColSize, pacific, i, 0); // left edge to pacific ocean
        dfs(heights, heightsSize, heightsColSize, atlantic, i, heightsColSize[i]-1); // right edge to altantic ocean
    }
    for(int j=0;j<heightsColSize[0];j++){
        dfs(heights, heightsSize, heightsColSize, pacific, 0, j); // top edge to pacific ocean
        dfs(heights, heightsSize, heightsColSize, atlantic, heightsSize-1, j); // bottom edge to altantic ocean
    }

    // count answer
    int count=0;
    for(int i=0;i<heightsSize;i++){
        for(int j=0;j<heightsColSize[i];j++){
            if(pacific[i][j] && atlantic[i][j]) count++;
        }
    }

    (*returnSize) = count;
    (*returnColumnSizes) = malloc(sizeof(int)*count);
    int **ans=malloc(sizeof(int*)*count);
    int id=0;
    for(int i=0;i<heightsSize;i++){
        for(int j=0;j<heightsColSize[i];j++){
            if(pacific[i][j] && atlantic[i][j]){
                ans[id]=malloc(sizeof(int)*2);
                ans[id][0]=i;
                ans[id][1]=j;
                (*returnColumnSizes)[id++]=2;
            }
        }
    }

    return ans;
}