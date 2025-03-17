/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include<stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSame(struct TreeNode* root, struct TreeNode* subRoot){
    if(!root && !subRoot) return true;
    else if(!root || !subRoot || root->val != subRoot->val) return false;
    return root->val==subRoot->val && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if(!root) return false;
    if(root->val == subRoot->val){
        if(isSame(root, subRoot)) return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}