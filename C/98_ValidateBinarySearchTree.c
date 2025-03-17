/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <limits.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool validate(struct TreeNode *root, long max, long min){
    if(!root) return true; // valid BST
    if(root->val<=min || root->val>=max) return false;
    return validate(root->left, root->val, min) && validate(root->right, max, root->val);
}

bool isValidBST(struct TreeNode* root) {
    return validate(root, LONG_MAX, LONG_MIN);
}