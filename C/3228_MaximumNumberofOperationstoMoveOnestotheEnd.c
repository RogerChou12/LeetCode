int maxOperations(char* s) {
    int ans=0, one=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='1'){
            one++;
        }
        else{
            while(i<strlen(s) && s[i]!='1'){
                i++;
            }
            ans+=one;
            one++; // s[i]=1 after skipping over consecutive '0's
        }
    }
    return ans;
}