#include<limits.h>

int max(int x, int y){
    return (x>y)?x:y;
}

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(nums1Size<nums2Size) return maxDotProduct(nums2, nums2Size, nums1, nums1Size);
    int dp[2][501];
    for(int i=0;i<2;i++){
        for(int j=0;j<501;j++){
            dp[i][j]=INT_MIN;
        }
    }
    int ans=INT_MIN;
    for(int i=nums1Size-1;i>=0;i--){
        for(int j=nums2Size-1;j>=0;j--){
            int x=nums1[i]*nums2[j];
            int tmp=dp[i&1][j];
            tmp=max(tmp, x); // start new subsequence
            tmp=max(tmp, x+((i+1<nums1Size & j+1<nums2Size)?dp[(i+1)&1][j+1]:0)); // extend subsequence
            tmp=max(tmp, dp[i&1][j+1]); // skip nums2[j]
            tmp=max(tmp, dp[(i+1)&1][j]); // skip nums1[i]
            dp[i&1][j]=tmp;
            ans=max(ans, dp[i&1][j]);
        }
    }
    return ans;
}