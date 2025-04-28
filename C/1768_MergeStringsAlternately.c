char * mergeAlternately(char * word1, char * word2){
    int len1=strlen(word1), len2=strlen(word2);
    char *ans = malloc(sizeof(char)*(len1+len2+1));
    int k=0;

    for(int i=0;i<fmax(len1, len2);i++){
        if(i < len1){
            ans[k++] = word1[i];
        }
        if(i < len2){
            ans[k++] = word2[i];
        }
    }
    ans[k] = '\0';
    return ans;
}