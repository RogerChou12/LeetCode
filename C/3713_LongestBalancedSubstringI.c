int longestBalanced(char* s) {
    int ans=0;
    int n=strlen(s);
    for(int i=0;i<n;i++){
        int freq[26]={0};
        int distinct=0, maxF=0, len=1;
        for(int j=i;j<n;j++, len++){
            int idx=s[j]-'a';
            if(freq[idx]==0){
                distinct++;
            }
            freq[idx]++;
            maxF=fmax(maxF, freq[idx]);
            if(len==distinct*maxF){
                ans=fmax(ans, len);
            }
        }
    }
    return ans;
}