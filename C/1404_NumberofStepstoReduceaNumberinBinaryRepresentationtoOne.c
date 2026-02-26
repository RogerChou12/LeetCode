int numSteps(char* s) {
    int end=strlen(s)-1;
    int count=0;
    while(end>0){
        if(s[end]=='1'){
            int i=end;
            while(i>=0 && s[i]!='0'){
                s[i]='0';
                i--;
            }
            if(i<0){
                s[0]='1'; // (integer+1)/2
                count++;
            }
            else{
                s[i]='1';
            }
        }
        else{
            end--;
        }
        count++;
    }
    return count;
}