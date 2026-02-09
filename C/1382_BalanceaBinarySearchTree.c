/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include<stdlib.h>

 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

 void inorderTraversal(struct TreeNode *root, struct TreeNode ***inorder, int *size){
    if(root==NULL) return;
    inorderTraversal(root->left, inorder, size);
    (*inorder)[(*size)++]=root;
    inorderTraversal(root->right, inorder, size);
}

struct TreeNode *createBalanceBST(struct TreeNode **inorder, int start, int end){
    if(start>end) return NULL;
    int mid=start+(end-start)/2;
    struct TreeNode *root=inorder[mid];
    root->left=createBalanceBST(inorder, start, mid-1);
    root->right=createBalanceBST(inorder, mid+1, end);
    return root;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    struct TreeNode **inorder=malloc(sizeof(struct TreeNode*)*10000);
    int inorderSize=0;
    inorderTraversal(root, &inorder, &inorderSize);
    struct TreeNode *ans=createBalanceBST(inorder, 0, inorderSize-1);
    free(inorder);
    return ans;
}