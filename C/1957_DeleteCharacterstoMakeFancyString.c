char* makeFancyString(char* s) {
    int same=0, current=2, len=strlen(s);

    if(len<3){
        return s;
    }

    for(int i=2;i<len;i++){
        if((s[i]!=s[current-1]) || (s[i]!=s[current-2])){
            s[current++] = s[i];
        }
    }

    s[current] = '\0';
    return s;
}