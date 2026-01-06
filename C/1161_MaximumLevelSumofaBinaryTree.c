/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include<limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxLevelSum(struct TreeNode* root) {
    long long maxSum=LLONG_MIN;
    int ans=0, level=0;
    struct TreeNode **queue=malloc(sizeof(struct TreeNode*)*10001);
    int head=0, end=0;
    queue[end++]=root;
    while(head<end){
        level++;
        int curSum=0;
        int curSize=end-head;
        for(int i=0;i<curSize;i++){
            struct TreeNode *node=queue[head++];
            curSum+=node->val;
            if(node->left) queue[end++]=node->left;
            if(node->right) queue[end++]=node->right;
        }
        if(maxSum<curSum){
            maxSum=curSum;
            ans=level;
        }
    }
    free(queue);
    return ans;
}