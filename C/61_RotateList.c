/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head){
        return head;
    }
    
    struct ListNode *end=head, *current=head;
    int length=1;

    while(end->next){
        length++;
        end=end->next;
    }

    k=k%length;
    if(k==0){
        return head;
    }
    for(int i=0;i<length-k-1;i++){
        current=current->next;
    }
    struct ListNode *newHead=current->next;
    current->next=NULL;
    end->next=head;

    return newHead;
}