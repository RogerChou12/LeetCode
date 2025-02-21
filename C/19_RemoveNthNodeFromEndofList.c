/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *fast=head, *slow=head;
    // move 'fast' n steps ahead
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    // If 'fast' becomes NULL, it means we need to remove the first node
    if(!fast){
        return head->next;
    }
    // 'slow' will point to the node before the one to be deleted
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return head;
}