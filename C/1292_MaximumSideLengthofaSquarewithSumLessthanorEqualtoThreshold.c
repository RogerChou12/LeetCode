int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int **prefix=malloc(sizeof(int*)*(matSize+1));
    for(int i=0;i<=matSize;i++){
        prefix[i]=calloc((matColSize[0]+1), sizeof(int));
    }
    for(int i=1;i<=matSize;i++){
        for(int j=1;j<=matColSize[0];j++){
            prefix[i][j]=mat[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    int right=fmin(matSize, matColSize[0]);
    int ans=0;
    for(int i=1;i<=matSize;i++){
        for(int j=1;j<=matColSize[0];j++){
            for(int side=ans+1;side<=right;side++){
                int x2=i+side-1, y2=j+side-1;
                if(i+side-1<=matSize && j+side-1<=matColSize[0] && prefix[x2][y2]-prefix[i-1][y2]-prefix[x2][j-1]+prefix[i-1][j-1]<=threshold){
                    ans=side;
                }
                else{
                    break;
                }
            }
        }
    }
    for(int i=0;i<=matSize;i++){
        free(prefix[i]);
    }
    free(prefix);
    return ans;
}