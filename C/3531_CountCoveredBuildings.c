int countCoveredBuildings(int n, int** buildings, int buildingsSize, int* buildingsColSize) {
    int ans=0;
    int *maxCol=calloc(n+1, sizeof(int));
    int *maxRow=calloc(n+1, sizeof(int));
    int *minCol=malloc(sizeof(int)*(n+1));
    int *minRow=malloc(sizeof(int)*(n+1));
    for(int i=0;i<=n;i++){
        minCol[i]=n+1;
        minRow[i]=n+1;
    }
    for(int i=0;i<buildingsSize;i++){
        int x=buildings[i][0];
        int y=buildings[i][1];
        maxCol[x]=fmax(maxCol[x], y);
        maxRow[y]=fmax(maxRow[y], x);
        minCol[x]=fmin(minCol[x], y);
        minRow[y]=fmin(minRow[y], x);
    }
    for(int i=0;i<buildingsSize;i++){
        int x=buildings[i][0];
        int y=buildings[i][1];
        if(x>minRow[y] && x<maxRow[y] && y>minCol[x] && y<maxCol[x]){
            ans++;
        }
    }
    free(maxCol);
    free(maxRow);
    free(minCol);
    free(minRow);
    return ans;
}