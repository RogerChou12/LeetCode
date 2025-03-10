/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int *ans = calloc(n+1, sizeof(int));
    (*returnSize) = n+1;

    for(int i=1;i<=n;i++){
        ans[i] = ans[i&(i-1)]+1; // turn off the rightmost set bit 
    }
    return ans;
}