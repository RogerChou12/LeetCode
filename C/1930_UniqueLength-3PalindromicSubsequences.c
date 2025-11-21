int countPalindromicSubsequence(char* s) {
    int *first=malloc(sizeof(int)*26);
    int *last=malloc(sizeof(int)*26);
    int ans=0;
    int sLen=strlen(s);
    memset(first, -1, sizeof(int)*26);
    memset(last, -1, sizeof(int)*26);
    for(int i=0;i<sLen;i++){
        int c=s[i]-'a';
        if(first[c]==-1){
            first[c]=i;
        }
        last[c]=i;
    }
    for(int i=0;i<26;i++){
        if(first[i]==-1) continue;
        int *between=calloc(26, sizeof(int));
        for(int j=first[i]+1;j<last[i];j++){
            int c=s[j]-'a';
            if(between[c]==0){
                ans++;
            }
            between[c]++;
        }
    }
    return ans;
}