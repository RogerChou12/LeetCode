#define MOD 1000000007
int numberOfPaths(int** grid, int gridSize, int* gridColSize, int k) {
    int m=gridSize, n=gridColSize[0];
    long long ***dp=malloc(sizeof(long long**)*(m+1));
    for(int i=0;i<=m;i++){
        dp[i]=malloc(sizeof(long long*)*(n+1));
        for(int j=0;j<=n;j++){
            dp[i][j]=calloc(k, sizeof(long long));
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i==1 && j==1){
                dp[i][j][grid[0][0]%k]=1;
                continue;
            }
            int value=grid[i-1][j-1]%k;
            for(int r=0;r<k;r++){
                int preR=(r-value+k)%k;
                dp[i][j][r]=(dp[i-1][j][preR]+dp[i][j-1][preR])%MOD;
            }
        }
    }
    int ans=dp[m][n][0];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);
    return ans;
}