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

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head) return NULL;

    struct ListNode *ans = head;
    while(ans){
        if(ans->next && ans->val==ans->next->val){
            ans->next = ans->next->next;
        }
        else{
            ans = ans->next;
        }
    }
    return head;
}