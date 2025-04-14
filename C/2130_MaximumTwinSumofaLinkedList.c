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

int pairSum(struct ListNode* head) {
    struct ListNode *slow=head, *fast=head;
    struct ListNode *previous=NULL, *nextNode=NULL;
    int max=0;

    while(fast && fast->next){
        fast = fast->next->next;
        // reverse first half list
        nextNode = slow->next;
        slow->next = previous;
        previous = slow;
        slow = nextNode;
    }
    // previous: reversed first half list
    // slow: second half list
    while(slow){
        int sum = slow->val + previous->val;
        max = fmax(max, sum);
        slow = slow->next;
        previous = previous->next;
    }
    return max;
}