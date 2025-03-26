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

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *nodeA=headA, *nodeB=headB;

    while(nodeA != nodeB){
        if(nodeA) nodeA = nodeA->next;
        else nodeA = headB;

        if(nodeB) nodeB = nodeB->next;
        else nodeB = headA;
    }
    return nodeA;
}