int maxProfit(int* prices, int pricesSize) {
    int min=prices[0], profit=0;

    for(int i=0;i<pricesSize;i++){
        profit = fmax(profit, (prices[i]-min));
        min = fmin(min, prices[i]);
    }

    return profit;
}