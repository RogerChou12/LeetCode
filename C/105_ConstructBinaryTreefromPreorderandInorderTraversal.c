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

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize==0) return NULL;

    struct TreeNode *ans = malloc(sizeof(struct TreeNode));
    ans->val = preorder[0]; // root
    ans->left = NULL;
    ans->right = NULL;

    int left_size=0;
    for(left_size=0;left_size<inorderSize;left_size++){
        if(inorder[left_size]==ans->val) break; // find the root and size of left tree
    }
    ans->left = buildTree(&preorder[1], left_size, inorder, left_size);
    ans->right = buildTree(&preorder[left_size+1], preorderSize-1-left_size, &inorder[left_size+1], inorderSize-1-left_size);

    return ans;
}