char* generateString(char* str1, char* str2) {
    int n=strlen(str1), m=strlen(str2);
    char *ans=malloc(sizeof(char)*(n+m));
    int *fixed=calloc((m+n-1), sizeof(int));
    for(int i=0;i<(m+n);i++){
        ans[i]='a';
    }
    ans[m+n-1]='\0';
    for(int i=0;i<n;i++){
        if(str1[i]=='T'){
            for(int j=i;j<i+m;j++){
                if(fixed[j]==1 && ans[j]!=str2[j-i]){
                    free(ans);
                    free(fixed);
                    return "";
                }
                else{
                    ans[j]=str2[j-i];
                    fixed[j]=1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(str1[i]=='F'){
            int flag=0, idx=-1;
            for(int j=i+m-1;j>=i;j--){
                if(str2[j-i]!=ans[j]){
                    flag=1;
                }
                if(idx==-1 && fixed[j]==0){
                    idx=j;
                }
            }
            if(flag){
                continue;
            }
            else if(idx!=-1){
                ans[idx]='b';
            }
            else{
                free(ans);
                free(fixed);
                return "";
            }
        }
    }
    free(fixed);
    return ans;
}