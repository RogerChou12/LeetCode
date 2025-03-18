#include<stdbool.h>

bool isAnagram(char* s, char* t) {
    int lenS=strlen(s), lenT=strlen(t);
    if(lenS != lenT) return false;

    int *hashTable = calloc(26, sizeof(int));
    for(int i=0;i<lenS;i++){
        hashTable[s[i]-'a']++;
    }
    for(int i=0;i<lenT;i++){
        if((--hashTable[t[i]-'a']) < 0) return false;
    }

    return true;
}