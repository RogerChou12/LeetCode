/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(!root){
        (*returnColumnSizes) = NULL;
        (*returnSize) = 0;
        return NULL;
    }
    struct TreeNode *queue[2000]; // store the nodes
    int start=0,end=0;
    int levels=0;
    int **ans = malloc(sizeof(int*)*2000);
    (*returnColumnSizes) = malloc(sizeof(int)*2000);
    queue[end++] = root; // the first node

    // start=end -> the end of the tree
    while(start<end){
        int level_size = end-start;
        (*returnColumnSizes)[levels] = level_size;
        ans[levels] = malloc(sizeof(int)*level_size);
        for(int i=0;i<level_size;i++){
            struct TreeNode *node = queue[start++]; // pop out the front element of the queue
            ans[levels][i] = node->val;
            if(node->left) queue[end++] = node->left;
            if(node->right) queue[end++] = node->right;
        }
        levels++; // move to next level of the binary tree
    }

    (*returnSize) = levels;
    return ans;
}