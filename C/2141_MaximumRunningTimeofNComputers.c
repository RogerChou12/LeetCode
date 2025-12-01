long long maxRunTime(int n, int* batteries, int batteriesSize) {
    long long left=1;
    long long right=0;
    for(int i=0;i<batteriesSize;i++){
        right+=batteries[i];
    }
    right/=n;
    while(left<right){
        long long target=right-(right-left)/2;
        long long run=0;
        for(int i=0;i<batteriesSize;i++){
            run+=fmin(batteries[i], target);
        }
        if(run/n>=target){
            left=target;
        }
        else{
            right=target-1;
        }
    }
    return left;
}