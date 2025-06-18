int largestCombination(int* candidates, int candidatesSize) {
    int ans=0;
    // Position of current bit
    for(int i=0;i<25;i++){
        int bits = 0;
        for(int j=0;j<candidatesSize;j++){
            bits += (candidates[j]>>i) & 1;
        }
        ans = fmax(ans, bits);
    }
    return ans;
}