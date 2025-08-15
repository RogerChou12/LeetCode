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

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode dummy1={0, NULL};
    struct ListNode dummy2={0, NULL};
    struct ListNode *less=&dummy1;
    struct ListNode *greater=&dummy2;

    while(head){
        if(head->val < x){
            less->next=head;
            less=less->next;
        }
        else{
            greater->next=head;
            greater=greater->next;
        }
        head=head->next;
    }
    greater->next=NULL;
    less->next=dummy2.next;
    return dummy1.next;
}