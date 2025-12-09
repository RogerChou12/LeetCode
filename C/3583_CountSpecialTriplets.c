#include<stdio.h>

#define MOD 1000000007
#define SIZE 100007

typedef struct HashTable{
    int key;
    int val;
    struct HashTable *next;
}HashTable;

HashTable *find(HashTable *head, int key){
    while(head){
        if(head->key==key){
            return head;
        }
        head=head->next;
    }
    return NULL;
}

void add(HashTable **head, int key, int value){
    int idx=key%SIZE;
    
    HashTable *tmp=find(head[idx], key);
    if(!tmp){
        tmp=malloc(sizeof(HashTable));
        tmp->key=key;
        tmp->val=value;
        tmp->next=head[idx];
        head[idx]=tmp;
    }
    else{
        tmp->val++;
    }
}

int getValue(HashTable **head, int key){
    int idx=key%SIZE;
    HashTable *tmp=find(head[idx], key);
    if(!tmp){
        return 0;
    }
    return tmp->val;
}

int specialTriplets(int* nums, int numsSize) {
    HashTable *total[SIZE]={0};
    HashTable *partial[SIZE]={0};
    long long ans=0;
    for(int i=0;i<numsSize;i++){
        add(total, nums[i], 1);
    }
    for(int i=0;i<numsSize;i++){
        int target=nums[i]*2;
        int left=getValue(partial, target);
        
        add(partial, nums[i], 1);

        int right=getValue(total, target)-getValue(partial, target);
        ans=(ans+(long long)left*right)%MOD;
    }
    
    return ans;
}