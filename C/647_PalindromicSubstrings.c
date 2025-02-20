int countSubstrings(char* s) {
    int s_len=strlen(s);
    bool **palindromic=malloc(sizeof(bool*)*s_len);
    for(int i=0;i<s_len;i++){
        palindromic[i]=calloc(s_len, sizeof(bool));
    }
    int count=0;

    // sub_len from 1 to s_len
    for(int sublen=1;sublen<=s_len;sublen++){
        //start of substring
        for(int i=0;i<s_len-sublen+1;i++){
            //start and end of substring should be the same
            if(s[i]==s[i+sublen-1] && (sublen<=2 || palindromic[i+1][i+sublen-2])){
                palindromic[i][i+sublen-1]=true;
                count++;
            }
        }
    }
    return count;
}