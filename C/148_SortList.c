/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge(struct ListNode* first, struct ListNode* second){
    struct ListNode *mergestart, *ptr;
    if(first->val < second->val){
        mergestart = first;
        first = first->next;
    }
    else{
        mergestart = second;
        second = second->next;
    }
    ptr = mergestart;
    while(first && second){
        if(first->val < second->val){
            ptr->next = first;
            first = first->next;
        }
        else{
            ptr->next = second;
            second = second->next;
        }
        ptr = ptr->next;
    }
    if(first) ptr->next = first;
    if(second) ptr->next = second;

    return mergestart;
}

struct ListNode* divide(struct ListNode* root){
    if(!root || !root->next) return root;

    struct ListNode *leftend, *rightstart=root, *fast=root;

    while(fast && fast->next){
        leftend = rightstart;
        rightstart = rightstart->next;
        fast = fast->next->next;
    }
    leftend->next = NULL;
    return rightstart;
}

struct ListNode* mergesort(struct ListNode* root){
    struct ListNode *left, *right, *mergeList;
    if(root && root->next){
        left =  root;
        right = divide(left);
        left = mergesort(left);
        right = mergesort(right);
        mergeList = merge(left, right);
        return mergeList;
    }
    return root;
}

struct ListNode* sortList(struct ListNode* head) {
    head = mergesort(head);
    return head;
}