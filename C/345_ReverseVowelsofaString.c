char* reverseVowels(char* s) {
    int left=0, right=strlen(s)-1;
    while(left < right){
        char s_left = tolower(s[left]);
        char s_right = tolower(s[right]);
        while((left<right) && (s_left!='a' && s_left!='e' && s_left!='i' && s_left!='o' && s_left!='u')){
            s_left = tolower(s[++left]);
        }
        while((left<right) && (s_right!='a' && s_right!='e' && s_right!='i' && s_right!='o' && s_right!='u')){
            s_right = tolower(s[--right]);
        }
        
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    return s;
}
