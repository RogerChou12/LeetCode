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

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode **current=&head; // 'current' point to 'head', able to change 'head'

    while(*current){
        struct ListNode *forward=(*current);
        // There are duplicates
        if(forward->next && forward->val==forward->next->val){
            int duplicate = forward->val;
            // Skip duplicates
            while(forward && forward->val==duplicate){
                forward = forward->next;
            }
            (*current) = forward;
        }
        // No duplicates
        else{
            current = &(forward->next);
        }
        
    }

    return head;
}