int peopleAwareOfSecret(int n, int delay, int forget) {
    long long MOD=1000000007;
    long long *dp=malloc(sizeof(long long)*(n+1)); //How many people learn the secret on day 'day'.
    long long share=0, ans=0;
    dp[0]=1;

    for(int day=1;day<n;day++){
        if(day-delay>=0){
            share=(share+dp[day-delay]+MOD)%MOD;
        }
        if(day-forget>=0){
            share=(share-dp[day-forget]+MOD)%MOD;
        }
        dp[day]=share;
    }
    for(int day=n-forget;day<n;day++){
        ans=(ans+dp[day])%MOD;
    }
    return (int)ans;
}