/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *merge(struct ListNode *list1, struct ListNode *list2){
    if(!list1) return list2;
    if(!list2) return list1;
    if(list1->val < list2->val){
        list1->next = merge(list1->next, list2);
        return list1;
    }
    else{
        list2->next = merge(list1, list2->next);
        return list2;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize==0) return NULL;
    if(listsSize==1) return lists[0];

    struct ListNode *ans=merge(lists[0], lists[1]);
    for(int i=2;i<listsSize;i++){
        ans = merge(ans, lists[i]);
    }
    return ans;
}