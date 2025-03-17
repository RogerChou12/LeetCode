int longestCommonSubsequence(char* text1, char* text2) {
    int len1=strlen(text1), len2=strlen(text2);
    int **len_sub = malloc(sizeof(int*)*(len1+1));
    for(int i=0;i<=len1;i++){
        len_sub[i] = calloc((1+len2), sizeof(int));
    }

    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            len_sub[i+1][j+1] = (text1[i]==text2[j])?len_sub[i][j]+1:fmax(len_sub[i+1][j], len_sub[i][j+1]);
        }
    }
    return len_sub[len1][len2];
}