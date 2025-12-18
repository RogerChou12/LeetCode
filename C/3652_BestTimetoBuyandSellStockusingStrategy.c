long long maxProfit(int* prices, int pricesSize, int* strategy, int strategySize, int k) {
    long long *pricesum=calloc((pricesSize+1), sizeof(long long));
    long long *profitsum=calloc((pricesSize+1), sizeof(long long));
    for(int i=0;i<pricesSize;i++){
        pricesum[i+1]=pricesum[i]+prices[i];
        profitsum[i+1]=profitsum[i]+prices[i]*strategy[i];
    }
    long long ans=profitsum[pricesSize];
    for(int i=k-1;i<pricesSize;i++){
        long long left=profitsum[i-k+1];
        long long right=profitsum[pricesSize]-profitsum[i+1];
        long long change=pricesum[i+1]-pricesum[i-k/2+1];
        ans=fmax(ans, (left+right+change));
    }
    return ans;
}