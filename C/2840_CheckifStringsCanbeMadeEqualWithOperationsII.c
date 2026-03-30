#include<stdbool.h>

bool checkStrings(char* s1, char* s2) {
    if(strlen(s1)!=strlen(s2)) return false;
    int count[256]={0};
    for(int i=0;i<strlen(s1);i++){
        int offset=(i&1)<<7; // odd or even
        count[offset+s1[i]]++;
        count[offset+s2[i]]--;
    }
    for(int i=0;i<256;i++){
        if(count[i]!=0){
            return false;
        }
    }
    return true;
}