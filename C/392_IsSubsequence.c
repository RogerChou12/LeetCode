#include<stdbool.h>

bool isSubsequence(char* s, char* t) {
    int sub=0, slen=strlen(s), tlen=strlen(t);

    for(int i=0;i<tlen;i++){
        if(s[sub] == t[i]){
            sub++;
        }
    }
    return sub==slen;
}