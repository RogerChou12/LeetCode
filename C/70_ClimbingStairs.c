int climbStairs(int n) {
    if(n<3){
        return n;
    }
    int* steps = malloc(sizeof(int)*(n+1));
    steps[0] = 0;
    steps[1] = 1; // there's 1 way to reach the top in 1 steps.
    steps[2] = 2; // there's 2 way to reach the top in 2 steps.
    for(int i=3;i<=n;i++){
        steps[i] = steps[i-1]+steps[i-2];
    }
    return steps[n];
}