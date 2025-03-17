/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>

typedef struct{
    int value;
    int count;
}hash;

int cmpInt(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int cmpHash(const void *a, const void *b){
    const hash* ha = (const hash*) a;
    const hash* hb = (const hash*) b;
    return ha->count-hb->count;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // only one integer in 'nums'
    if(numsSize==1 && k==1){
        (*returnSize) = 1;
        return nums;
    }
    // no integer or k>numsSize
    if(!numsSize || k==0 || k>numsSize) return NULL;
    
    int *ans = malloc(sizeof(int)*k);
    int integer=0; // number of unique numbers
    hash *hashtable = malloc(sizeof(hash)*numsSize);

    qsort(nums, numsSize, sizeof(int), cmpInt);
    for(int i=0;i<numsSize;i++){
        if(i==0 || nums[i]!=hashtable[integer-1].value){
            hashtable[integer].value = nums[i];
            hashtable[integer].count = 1;
            integer++;
        }
        else{
            hashtable[integer-1].count += 1;
        }
    }

    qsort(hashtable, integer, sizeof(hash), cmpHash);
    for(int i=0;i<k;i++){
        ans[i] = hashtable[integer-1-i].value;
    }
    (*returnSize) = k;
    return ans;
}