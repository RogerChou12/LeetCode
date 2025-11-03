int minCost(char* colors, int* neededTime, int neededTimeSize) {
    int sum=0;
    for(int i=1;i<neededTimeSize;i++){
        if(colors[i]==colors[i-1]){
            sum+=fmin(neededTime[i], neededTime[i-1]);
            neededTime[i]=fmax(neededTime[i], neededTime[i-1]);
        }
    }
    return sum;
}