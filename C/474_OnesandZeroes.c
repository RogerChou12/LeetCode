int findMaxForm(char** strs, int strsSize, int m, int n) {
    int *dp=calloc((m+1)*(n+1), sizeof(int*));
    for(int i=0;i<strsSize;i++){
        int zero=0, one=0;
        for(int j=0;strs[i][j];j++){
            if(strs[i][j]=='1'){
                one++;
            }
            else{
                zero++;
            }
        }
        for(int x=m;x>=zero;x--){
            for(int y=n;y>=one;y--){
                int idx=x*(n+1)+y;
                int pre=(x-zero)*(n+1)+(y-one);
                if(dp[idx]<dp[pre]+1){
                    dp[idx]=dp[pre]+1;
                }
            }
        }
    }
    int ans=dp[m*(n+1)+n];
    free(dp);
    return ans;
}