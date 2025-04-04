/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow=head, *fast=head;

    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}