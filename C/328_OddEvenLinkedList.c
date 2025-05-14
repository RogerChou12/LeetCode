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

struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head) return NULL;
    if(!head->next) return head;

    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    struct ListNode *even_start = even;

    while(even && even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = even_start;
    return head;
}