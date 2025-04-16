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

struct ListNode* deleteMiddle(struct ListNode* head) {
    if(!head->next) return NULL; // n=1, the middle node is 0

    struct ListNode *slow = head;
    struct ListNode *fast = head->next->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = slow->next->next;
    return head;
}