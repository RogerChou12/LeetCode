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

 struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode *temp=head, *left=head, *right=head;
    
    for(int i=1;i<k;i++){
        left = left->next;
        temp = temp->next;
    }
    
    while(temp && temp->next){
        temp = temp->next;
        right = right->next;
    }

    // Swap 2 nodes
    int value = left->val;
    left->val = right->val;
    right->val = value;

    return head;
}