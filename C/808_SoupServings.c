#define MAX(a,b) (a>b?a:b)
double soupServings(int n) {
    if(n>5000) return 1;
    int servings=ceil(n/25.0);
    double dp[servings+1][servings+1];
    dp[0][0]=0.5;

    for(int k=1;k<=servings;k++){
        dp[0][k]=1;
        dp[k][0]=0;
        for(int j=1;j<=k;j++){
            dp[j][k]=0.25*(dp[MAX(0,j-4)][k]+dp[MAX(0,j-3)][k-1]+dp[MAX(0,j-2)][MAX(0,k-2)]+dp[MAX(0,j-1)][MAX(0,k-3)]);
            dp[k][j]=0.25*(dp[MAX(0,k-4)][j]+dp[MAX(0,k-3)][j-1]+dp[MAX(0,k-2)][MAX(0,j-2)]+dp[k-1][MAX(0,j-3)]);
        }
        if(dp[k][k]>(1-(1e-5))){
            return 1;
        }
    }
    return dp[servings][servings];
}