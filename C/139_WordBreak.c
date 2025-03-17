#include<stdbool.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int s_len = strlen(s);
    bool *check = calloc(s_len+1, sizeof(bool)); //track whether substrings can be formed
    check[0]=true; // an empty string can always be segmented

    for(int i=0;i<s_len;i++){
        if(check[i]){
            // start search the next segment
            for(int j=0;j<wordDictSize;j++){
                // the first letter of 's' and 'wordDict[j] is the same
                if((s+i)[0]==wordDict[j][0]){
                    // search substring
                    if(strstr((s+i), wordDict[j])==(s+i)){
                        check[i+strlen(wordDict[j])] = true;
                    }
                }
            }
        }
    }
    return check[s_len];
}