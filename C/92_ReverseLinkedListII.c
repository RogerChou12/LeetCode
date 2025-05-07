/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode *dummyNode = malloc(sizeof(struct ListNode));
    dummyNode->val = 0;
    dummyNode->next = head;
    struct ListNode *previous, *forward;
    previous = dummyNode;
    for(int i=0;i<(left-1);i++){
        previous = previous->next; // The node before position 'left' of list
    }

    struct ListNode *current = previous->next;
    for(int i=0;i<(right-left);i++){
        forward = current->next;
        current->next = forward->next;
        forward->next = previous->next;
        previous->next = forward;
    }
    return dummyNode->next;
}