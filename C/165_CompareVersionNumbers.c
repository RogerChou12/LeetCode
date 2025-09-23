int compareVersion(char* version1, char* version2) {
    int i=0, j=0, len1=strlen(version1), len2=strlen(version2);
    while(i<len1 || j<len2){
        int x1=0, x2=0;
        while(i<len1 && version1[i]!='.'){
            x1=10*x1+(version1[i++]-'0');
        }
        while(j<len2 && version2[j]!='.'){
            x2=10*x2+(version2[j++]-'0');
        }
        i++;
        j++;
        if(x1>x2) return 1;
        else if(x1<x2) return -1;
    }
    return 0;
}