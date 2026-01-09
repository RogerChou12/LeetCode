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

 struct Pair{
    struct TreeNode *node;
    int depth;
};

struct Pair dfs(struct TreeNode *root){
    if(!root) return (struct Pair){NULL, 0};
    struct Pair left=dfs(root->left);
    struct Pair right=dfs(root->right);
    if(left.depth>right.depth){
        return (struct Pair){left.node, left.depth+1};
    }
    else if(left.depth<right.depth){
        return (struct Pair){right.node, right.depth+1};
    }
    return (struct Pair){root, left.depth+1};
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    return dfs(root).node;
}