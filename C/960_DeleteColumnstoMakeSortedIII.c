#include<stdbool.h>

int minDeletionSize(char** strs, int strsSize) {
    int n=strlen(strs[0]);
    int *dp=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        dp[i]=1;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            bool yes=true;
            for(int s=0;s<strsSize;s++){
                if(strs[s][i]>strs[s][j]){
                    yes=false;
                    break;
                }
            }
            if(yes){
                dp[i]=fmax(dp[i], 1+dp[j]);
            }
        }
    }
    int max_dp=0;
    for(int i=0;i<n;i++){
        max_dp=fmax(dp[i], max_dp);
    }
    return n-max_dp;
}