#include <limits.h>

int max(int *sum, int k){
    int maximum=sum[0];
    for(int i=1;i<k;i++){
        if(sum[i]>maximum){
            maximum = sum[i];
        }
    }
    return maximum;
}

void distribute(int* cookies, int cookiesSize, int k, int start, int *ans, int *sum){
    if(start==cookiesSize){
        int maximum = max(sum, k);
        if(maximum < (*ans)){
            (*ans) = maximum;
        }
    }
    else{
        for(int i=0;i<k;i++){
            sum[i] += cookies[start];
            if(max(sum, k) < (*ans)){
                distribute(cookies, cookiesSize, k, start+1, ans, sum);
            }
            sum[i] -= cookies[start];
            if(sum[i]==0){
                break;
            }
        }
    }
}

int distributeCookies(int* cookies, int cookiesSize, int k) {
    int ans = INT_MAX;
    int *sum = calloc(k, sizeof(int));
    distribute(cookies, cookiesSize, k, 0, &ans, sum);
    return ans;
}