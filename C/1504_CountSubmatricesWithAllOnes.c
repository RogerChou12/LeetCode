int numSubmat(int** mat, int matSize, int* matColSize) {
    int ans=0;
    int **count=malloc(sizeof(int*)*matSize);
    for(int i=0;i<matSize;i++){
        count[i]=calloc(matColSize[i], sizeof(int));
    }

    for(int i=0;i<matSize;i++){
        for(int j=0;j<matColSize[i];j++){
            if(j==0){
                count[i][j]=mat[i][j];
            }
            else{
                count[i][j]=(mat[i][j]==1)?(count[i][j-1]+1):0;
            }
            int cur=count[i][j];
            for(int k=i;k>=0;k--){
                cur=(cur<count[k][j])?cur:count[k][j];
                if(cur==0){
                    break;
                }
                ans+=cur;
            }
        }
    }
    for(int i=0;i<matSize;i++){
        free(count[i]);
    }
    free(count);
    return ans;
}