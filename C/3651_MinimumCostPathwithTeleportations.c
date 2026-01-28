#include<stdio.h>
#include<limits.h>

static int **gridptr=NULL;

int cmp(const void *a, const void *b){
    int *pa=(int*)a;
    int *pb=(int*)b;
    return gridptr[pa[0]][pa[1]]-gridptr[pb[0]][pb[1]];
}

int minCost(int** grid, int gridSize, int* gridColSize, int k) {
    gridptr=grid;
    int pointsSize=gridSize*gridColSize[0];
    int points[pointsSize][2];
    int idx=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            points[idx][0]=i;
            points[idx][1]=j;
            idx++;
        }
    }
    qsort(points, pointsSize, sizeof(points[0]), cmp);
    int cost[gridSize][gridColSize[0]];
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            cost[i][j]=INT_MAX;
        }
    }
    for(int t=0;t<=k;t++){
        int minCost=INT_MAX;
        for(int i=0, j=0;i<pointsSize;i++){
            minCost=fmin(minCost, cost[points[i][0]][points[i][1]]);
            if(i+1<pointsSize && grid[points[i][0]][points[i][1]]==grid[points[i+1][0]][points[i+1][1]]){
                continue;
            }
            for(int r=j;r<=i;r++){
                cost[points[r][0]][points[r][1]]=minCost;
            }
            j=i+1;
        }
        for(int i=gridSize-1;i>=0;i--){
            for(int j=gridColSize[0]-1;j>=0;j--){
                if(i==gridSize-1 && j==gridColSize[0]-1){
                    cost[i][j]=0;
                    continue;
                }
                if(i!=gridSize-1){
                    cost[i][j]=fmin(cost[i][j], cost[i+1][j]+grid[i+1][j]);
                }
                if(j!=gridColSize[0]-1){
                    cost[i][j]=fmin(cost[i][j], cost[i][j+1]+grid[i][j+1]);
                }
            }
        }
    }
    return cost[0][0];
}