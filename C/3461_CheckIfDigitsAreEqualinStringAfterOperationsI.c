#include<stdbool.h>

bool hasSameDigits(char* s) {
    int n=strlen(s);
    // Perform n-2 operations
    for(int op=0;op<n-2;op++){
        for(int i=0;i<n-1-op;i++){
            s[i]=((s[i]-'0')+(s[i+1]-'0'))%10 + '0';
        }
    }

    return s[0]==s[1];
}