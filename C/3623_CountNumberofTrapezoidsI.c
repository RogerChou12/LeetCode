#include<uthash.h>

typedef struct{
    int key;
    int val;
    UT_hash_handle hh;
}HashItem;

HashItem *hashFind(HashItem **hashtable, int key){
    HashItem *result=NULL;
    HASH_FIND_INT(*hashtable, &key, result);
    return result;
}

void hashAdd(HashItem **hashtable, int key, int val){
    if(hashFind(hashtable, key)) return;
    HashItem *result=malloc(sizeof(HashItem));
    result->key=key;
    result->val=val;
    HASH_ADD_INT(*hashtable, key, result);
    return;
}

void hashSet(HashItem **hashtable, int key, int val){
    HashItem *tmp=hashFind(hashtable, key);
    if(!tmp){
        hashAdd(hashtable, key, val);
    }
    else{
        tmp->val=val;
    }
    return;
}

int hashGet(HashItem **hashtable, int key, int defaultValue){
    HashItem *find=hashFind(hashtable, key);
    if(!find){
        return defaultValue;
    }
    return find->val;
}

void hashFree(HashItem **hashtable){
    HashItem *curr=NULL, *tmp=NULL;
    HASH_ITER(hh, *hashtable, curr, tmp){
        HASH_DEL(*hashtable, curr);
        free(curr);
    }
}

int countTrapezoids(int** points, int pointsSize, int* pointsColSize) {
    HashItem *yGroup=NULL;
    long long ans=0, sum=0;
    const int MOD=1e9+7;
    for(int i=0;i<pointsSize;i++){
        hashSet(&yGroup, points[i][1], 1+hashGet(&yGroup, points[i][1], 0));
    }
    for(HashItem *group=yGroup;group;group=group->hh.next){
        int count=group->val;
        long long edge=(long long)count*(count-1)/2;
        ans+=edge*sum;
        sum+=edge;
    }
    hashFree(&yGroup);
    return ans%MOD;
}