/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *dummy=malloc(sizeof(struct ListNode));
    dummy->val=0;
    dummy->next=NULL;
    struct ListNode *ans=dummy;
    int carry=0;

    while(l1 || l2 || carry>0){
        int sum=0;
        if(l1){
            sum += l1->val;
            l1=l1->next;
        }
        if(l2){
            sum += l2->val;
            l2=l2->next;
        }

        sum += carry;
        carry = sum/10;

        struct ListNode *nextnode=malloc(sizeof(struct ListNode));
        nextnode->val=sum%10;
        nextnode->next=NULL;
        ans->next=nextnode;
        ans=nextnode;
    }
    return dummy->next;
}