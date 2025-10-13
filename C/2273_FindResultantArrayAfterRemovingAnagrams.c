/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdbool.h>

bool compare(char* word1, char* word2){
    int freq[26]={0};
    for(int i=0;word1[i]!='\0';i++){
        freq[word1[i]-'a']++;
    }
    for(int i=0;word2[i]!='\0';i++){
        freq[word2[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
}

char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    char **ans=malloc(sizeof(char*)*wordsSize);
    (*returnSize)=0;
    ans[(*returnSize)++]=words[0];

    for(int i=1;i<wordsSize;i++){
        if(!compare(words[i], words[i-1])){
            ans[(*returnSize)++]=words[i];
        }
    }

    return ans;
}