/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode *fast=head, *slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }

    // second half list
    struct ListNode *second=slow->next;
    struct ListNode *previous;
    struct ListNode *nextNode=NULL;
    // reverse the second list
    while(second){
        previous=second->next;
        second->next=nextNode;
        nextNode=second;
        second=previous;
    }
    // seperate list
    slow->next=NULL;
    second=nextNode; // the second list is reversed
    struct ListNode *first=head;
    while(second){
        struct ListNode *next1=first->next;
        struct ListNode *next2=second->next;
        first->next=second;
        second->next=next1;
        first=next1;
        second=next2;
    }
}