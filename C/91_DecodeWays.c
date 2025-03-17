#include<string.h>

int numDecodings(char* s) {
    int now=1, pre=0; // now=decoding ways from 'i+1', pre=decoding ways from 'i+2'
    int len=strlen(s);
    for(int i=len-1;i>=0;i--){
        int cur=(s[i]=='0')?0:now; // Single Digit Decoding, 0 cannot be decoded
        if(i<len-1 && (s[i]=='1' || s[i]=='2' && s[i+1]<'7')){
            cur += pre; // Two-Digit Decoding
        }
        pre=now;
        now=cur;
    }
    return now;
}