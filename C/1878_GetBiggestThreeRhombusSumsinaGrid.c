/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpInt(const void *a, const void *b){
    return *(int*)b-*(int*)a;
}

void heapPut(int *ans, int *count, int value){
    for(int i=0;i<*count;i++){
        if(ans[i]==value){
            return;
        }
    }
    if(*count<3){
        ans[(*count)++]=value;
        qsort(ans, *count, sizeof(int), cmpInt);
    }
    else if(value>ans[2]){
        ans[2]=value;
        qsort(ans, 3, sizeof(int), cmpInt);
    }
}

int* getBiggestThree(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int **tl_sum=malloc(sizeof(int*)*(gridSize+1));
    int **tr_sum=malloc(sizeof(int*)*(gridSize+1));
    for(int i=0;i<=gridSize;i++){
        tl_sum[i]=calloc(gridColSize[0]+2, sizeof(int));
        tr_sum[i]=calloc(gridColSize[0]+2, sizeof(int));
    }
    for(int i=1;i<=gridSize;i++){
        for(int j=1;j<=gridColSize[0];j++){
            tl_sum[i][j]=tl_sum[i-1][j-1]+grid[i-1][j-1];
            tr_sum[i][j]=tr_sum[i-1][j+1]+grid[i-1][j-1];
        }
    }
    int *ans=calloc(3, sizeof(int));
    int count=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            heapPut(ans, &count, grid[i][j]);
            for(int k=i+2;k<gridSize;k+=2){
                int ux=i, uy=j;
                int dx=k, dy=j;
                int lx=(i+k)/2, ly=j-(k-i)/2;
                int rx=(i+k)/2, ry=j+(k-i)/2;
                if(ly<0 || ry>=gridColSize[0]){
                    break;
                }
                int sum=(tr_sum[lx+1][ly+1]-tr_sum[ux][uy+2])+
                        (tl_sum[rx+1][ry+1]-tl_sum[ux][uy])+
                        (tr_sum[dx+1][dy+1]-tr_sum[rx][ry+2])+
                        (tl_sum[dx+1][dy+1]-tl_sum[lx][ly])-
                        (grid[ux][uy]+grid[dx][dy]+grid[lx][ly]+grid[rx][ry]);
                heapPut(ans, &count, sum);
            }
        }
    }
    for(int i=0;i<gridSize;i++){
        free(tl_sum[i]);
        free(tr_sum[i]);
    }
    free(tl_sum);
    free(tr_sum);
    (*returnSize)=count;
    return ans;
}