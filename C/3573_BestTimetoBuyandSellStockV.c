long long maximumProfit(int* prices, int pricesSize, int k) {
    long long **dp=malloc(sizeof(long long*)*(k+1));
    for(int i=0;i<=k;i++){
        dp[i]=calloc(3, sizeof(long long));
    }
    for(int j=1;j<=k;j++){
        dp[j][1]=-prices[0];
        dp[j][2]=prices[0];
    }
    for(int i=1;i<pricesSize;i++){
        for(int j=k;j>0;j--){
            dp[j][0]=fmax(dp[j][0], fmax(dp[j][2]-prices[i], dp[j][1]+prices[i]));
            dp[j][1]=fmax(dp[j][1], dp[j-1][0]-prices[i]);
            dp[j][2]=fmax(dp[j][2], dp[j-1][0]+prices[i]);
        }
    }
    long long ans=dp[k][0];
    for(int i=0;i<=k;i++){
        free(dp[i]);
    }
    free(dp);
    return ans;
}