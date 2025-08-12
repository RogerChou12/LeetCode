int numberOfWays(int n, int x) {
    const int mod=1000000007;
    int *sumofpower=calloc(n+1, sizeof(int));
    sumofpower[0]=1;
    for(int i=1;i<=n;i++){
        int val=pow(i, x);
        if(val>n){
            break;
        }
        for(int sum=n;sum>=val;sum--){
            sumofpower[sum] += sumofpower[sum-val];
            sumofpower[sum] %= mod;
        }
    }
    return sumofpower[n];
}