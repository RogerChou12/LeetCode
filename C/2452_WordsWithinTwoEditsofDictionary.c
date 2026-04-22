/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** twoEditWords(char** queries, int queriesSize, char** dictionary, int dictionarySize, int* returnSize) {
    char **ans=malloc(sizeof(char*)*queriesSize);
    int count=0;
    for(int i=0;i<queriesSize;i++){
        char *word=queries[i];
        for(int j=0;j<dictionarySize;j++){
            char *string=dictionary[j];
            int diff=0;
            for(int k=0;word[k]!='\0';k++){
                if(word[k]!=string[k]){
                    diff++;
                }
            }
            if(diff<=2){
                ans[count++]=word;
                break;
            }
        }
    }
    (*returnSize)=count;
    return ans;
}