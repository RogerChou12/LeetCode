int lengthOfLongestSubstring(char* s) {
    int start=0, end=0;
    int char_set[256] = {0};
    int max_len = 0;
    
    //expand end of substring
    for(end=0;s[end]!='\0';end++){
        // duplicate characters
        while(char_set[s[end]]){
            char_set[s[start]] = 0;
            start++;
        }
        char_set[s[end]]++;
        max_len = (end-start+1)>max_len?(end-start+1):max_len;
    }
    return max_len;
}