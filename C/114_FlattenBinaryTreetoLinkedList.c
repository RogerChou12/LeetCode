/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include<stdio.h>

 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten(struct TreeNode* root) {
    struct TreeNode *current = root;
    while(current){
        if(current->left){
            struct TreeNode *runner = current->left;
            while(runner->right){
                runner = runner->right;
            }
            runner->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}