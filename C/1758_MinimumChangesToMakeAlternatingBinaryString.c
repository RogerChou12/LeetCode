int minOperations(char* s) {
    int start0=0, start1=0;
    for(int i=0;s[i]!='\0';i++){
        if(i%2==0){
            if(s[i]=='0'){
                start1++;
            }
            else{
                start0++;
            }
        }
        else{
            if(s[i]=='1'){
                start1++;
            }
            else{
                start0++;
            }
        }
    }
    return (start1>start0)?start0:start1;
}