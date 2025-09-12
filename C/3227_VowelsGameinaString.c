#include<stdbool.h>
#include<string.h>

bool doesAliceWin(char* s) {
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if((0x104111 >> (s[i]-'a'))&1){
            return true;
        }
    }
    return false;
}