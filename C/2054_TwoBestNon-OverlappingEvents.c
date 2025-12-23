int cmpEvents(const void *a, const void *b){
    int *eventA=*(int**)a;
    int *eventB=*(int**)b;
    return eventA[0]-eventB[0];
}

int findEvents(int **events, int eventsSize, int idx, int count, int **dp){
    if(count==2 || idx>=eventsSize) return 0;
    if(dp[idx][count]==-1){
        int end=events[idx][1];
        // Find the first event starting after 'end'
        int left=idx+1, right=eventsSize-1;
        while(left<right){
            int mid=left+((right-left)>>1);
            if(events[mid][0]>end){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        // Include events[idx]
        int include=events[idx][2]+((left<eventsSize && events[left][0]>end)?findEvents(events, eventsSize, left, count+1, dp):0);
        // Exclude events[idx]
        int exclude=findEvents(events, eventsSize, idx+1, count, dp);
        dp[idx][count]=fmax(include, exclude);
    }
    return dp[idx][count];
}

int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {
    qsort(events, eventsSize, sizeof(int*), cmpEvents);
    int **dp=malloc(sizeof(int*)*eventsSize);
    for(int i=0;i<eventsSize;i++){
        dp[i]=malloc(sizeof(int)*3);
        for(int j=0;j<3;j++){
            dp[i][j]=-1;
        }
    }
    return findEvents(events, eventsSize, 0, 0, dp);
}