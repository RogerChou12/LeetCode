/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    const int mod=1000000007;
    int *powers=malloc(sizeof(int)*32);
    int *ans=malloc(sizeof(int)*queriesSize);
    int powersSize=0, power=0;
    while(n){
        if(n&1){
            int prefix=powersSize>0?powers[powersSize-1]:0;
            powers[powersSize++]=prefix+power;
        }
        n >>= 1;
        power++;
    }
    
    for(int i=0;i<queriesSize;i++){
        int start=queries[i][0], end=queries[i][1];
        int power=powers[end]-(start==0?0:powers[start-1]);
        ans[i]=1;
        for(int j=0;j<power;j++){
            ans[i]=ans[i]*2%mod;
        }
    }

    (*returnSize)=queriesSize;
    return ans;
}