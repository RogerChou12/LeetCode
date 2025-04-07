void reverse(int start, int end, char* s){
    while(start < end){
        char temp=s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

char* reverseWords(char* s) {
    int slen = strlen(s);
    int *endWord = malloc(sizeof(int)*slen);
    int end=0;
    for(int i=0;i<slen;i++){
        if(s[i] == ' '){
            endWord[end++] = i-1;
        }
    }
    endWord[end++] = slen-1;

    for(int i=0;i<end;i++){
        if(i==0){
            reverse(0, endWord[i], s);
        }
        else{
            reverse(endWord[i-1]+2, endWord[i], s);
        }
    }

    return s;
}