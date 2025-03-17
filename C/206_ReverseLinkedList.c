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

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *previous, *reverse=NULL;
    while(head){
        previous = head->next;
        head->next = reverse;
        reverse = head;
        head = previous; // move to next node
    }
    return reverse;
}