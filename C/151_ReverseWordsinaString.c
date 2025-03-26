void swap(char* a, char* b){
    char temp=*a;
    *a = *b;
    *b = temp;
}
char* reverseWords(char* s) {
    int slen = strlen(s);
    char *start=s, *end=s+(slen-1);
    // reverse all string
    while(start < end){
        swap(start, end);
        start++;
        end--;
    }

    char* index=s;
    start=s;
    end=s;
    // reverse words
    while(index < s+slen){
        while(index<s+slen && *index!=' '){
            *end = *index; // Move character to `end` (compacting the string)
            end++;
            index++;
        }
        // reverse the word
        if(start < end){

            char *start1=start, *end1=end-1;
            while(start1 < end1){
                swap(start1, end1);
                start1++;
                end1--;
            }
            //the end of word is the end of string
            if(end == s+(slen-1)){
                break;
            }
            //space at the end of word
            *end = ' ';
            end++;
            start = end; // to the next word
        }
        index++;
    }
    // end of string
    if(*(end-1) != ' '){
        *end = '\0';
    }
    else{
        *(end-1) = '\0';
    }
    return s;
}