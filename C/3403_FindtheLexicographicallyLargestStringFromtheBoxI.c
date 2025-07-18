char* answerString(char* word, int numFriends) {
    int len=strlen(word);
    int max_len=len-numFriends+1;
    char *ans=malloc((1+max_len)*sizeof(char));
    ans[0]='\0'; // Empty string

    if(numFriends==1){
        return word;
    }

    for(int i=0;i<len;i++){
        char *temp=malloc((1+max_len)*sizeof(char));
        strncpy(temp, word+i, max_len);
        temp[max_len]='\0';
        // 'temp is larger than 'ans'
        if(strcmp(temp, ans)>0){
            free(ans);
            ans=temp;
        }
    }
    return ans;
}