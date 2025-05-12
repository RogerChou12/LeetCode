/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
#include<stdio.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node* connect(struct Node* root) {
	if(!root){
        return NULL;
    }

    struct Node* parentNode=root;
    struct Node* current=NULL;
    while(parentNode->left){
        current = parentNode;
        while(current){
            current->left->next = current->right;
            if(current->next){
                current->right->next = current->next->left;
            }
            current = current->next;
        }
        parentNode = parentNode->left;
    }
    return root;
}