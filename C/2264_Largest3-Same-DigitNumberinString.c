char* largestGoodInteger(char* num) {
    char *ans=malloc(sizeof(char)*4);
    int max=-1, count=1;
    ans[0]='\0';

    for(int i=1;num[i]!='\0';i++){
        if(num[i]==num[i-1]){
            count++;
        }
        else{
            count=1;
        }
        if(count==3){
            int val=num[i]-'0';
            if(val>max){
                max=val;
                for(int j=0;j<3;j++){
                    ans[j]=num[i];
                }
            }
            ans[3]='\0';
        }
    }
    return ans;
}