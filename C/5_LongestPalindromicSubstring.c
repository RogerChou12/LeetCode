char* longestPalindrome(char* s) {
    if(!s){
        return s;
    }

    int s_len=strlen(s), sub_len=0, start=0, end=0, sub_start=0, center=0;
    for(start=0, end=0;sub_len<2*(s_len-center);start=center, end=center){
        while(end+1<s_len && s[end]==s[end+1]){
            end++; // expand end of substring
        }
        center=end+1; // new center for next loop
        //expand substring from start and end
        while(start>0 && end+1<s_len && s[start-1]==s[end+1]){
            start--;
            end++;
        }
        if(end-start+1>sub_len){
            sub_len=end-start+1;
            sub_start=start;
        }
    }
    s=s+sub_start;
    s[sub_len]='\0'; // end of string
    return s;
}