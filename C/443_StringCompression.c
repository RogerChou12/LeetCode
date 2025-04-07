int compress(char* chars, int charsSize) {
    int ans=0;

    for(int i=0;i<charsSize;i++){
        char current=chars[i];
        int same=0;
        while(i<charsSize && chars[i]==current){
            same++;
            i++;
        }
        chars[ans++] = current;

        if(same>1){
            char count[5]; // The max length is 2000.
            sprintf(count, "%d", same);
            for(int j=0;count[j]!='\0';j++){
                chars[ans++] = count[j];
            }
        }

        i--;
    }
    
    return ans;
}