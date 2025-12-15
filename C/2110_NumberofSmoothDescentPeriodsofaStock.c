long long getDescentPeriods(int* prices, int pricesSize) {
    long long ans=1;
    int descent=1;
    for(int i=1;i<pricesSize;i++){
        if(prices[i]==prices[i-1]-1){
            descent++;
        }
        else{
            descent=1;
        }
        ans+=descent;
    }
    return ans;
}