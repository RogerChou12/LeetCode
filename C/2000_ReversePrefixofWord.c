char* reversePrefix(char* word, char ch) {
    int end=0;
    // The index of the first occurrence of 'ch'
    while((word[end] != ch) && (word[end] != '\0')){
        end++;
    }
    if(word[end] == '\0'){
        return word;
    }
    // Reverse the segment
    int start=0;
    while(start < end){
        char temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start++;
        end--;
    }
    return word;
}