/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdbool.h>
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow=head, *fast=head;
    // find the middle of linked list
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    // reverse the half of linked list
    struct ListNode *reverse=slow;
    slow = slow->next;
    reverse->next = NULL;
    while(slow){
        struct ListNode *temp=slow->next; // Store next node
        slow->next = reverse; // Reverse the link
        reverse = slow; // Move 'reverse' forward
        slow = temp; // Move 'slow' forward
    }

    while(reverse){
        if(reverse->val!=head->val) return false;
        reverse = reverse->next;
        head = head->next;
    }
    return true;
}