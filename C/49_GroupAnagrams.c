/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdio.h>

typedef struct{
    char* original;
    char* sorted;
} Pair;

int cmpChar(const void* a, const void* b){
    return *(char*)a - *(char*)b;
}

int cmpPair(const void *a, const void *b){
    const Pair *pa=(const Pair*) a;
    const Pair *pb=(const Pair*) b;
    return strcmp(pa->sorted, pb->sorted);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    if(strsSize==0){
        (*returnSize)=0;
        return NULL;
    }

    char ***ans=malloc(sizeof(char**)*strsSize);
    int *column=malloc(sizeof(int)*strsSize);
    int groups=0;
    Pair *pairs=malloc(sizeof(Pair)*strsSize);

    // sort every word
    for(int i=0;i<strsSize;i++){
        char *sort_str=malloc(sizeof(char)*(1+strlen(strs[i])));
        strcpy(sort_str, strs[i]);
        qsort(sort_str, strlen(strs[i]), sizeof(char), cmpChar);
        pairs[i].original=strs[i];
        pairs[i].sorted=sort_str;
    }

    qsort(pairs, strsSize, sizeof(Pair), cmpPair);

    for(int i=0;i<strsSize;i++){
        if(i==0 || strcmp(pairs[i].sorted, pairs[i-1].sorted)!=0){
            ans[groups]=malloc(sizeof(char*));
            column[groups]=1;
            ans[groups][0]=pairs[i].original;
            groups++;
        }
        else{
            int lastgroup=groups-1;
            int count=column[lastgroup];
            ans[lastgroup]=realloc(ans[lastgroup], sizeof(char*)*(1+count));
            ans[lastgroup][count]=pairs[i].original;
            column[lastgroup]=count+1;
        }
    }

    (*returnColumnSizes)=column;
    (*returnSize)=groups;
    return ans;
}