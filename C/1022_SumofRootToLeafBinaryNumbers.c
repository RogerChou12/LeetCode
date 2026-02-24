/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

 int dfs(struct TreeNode *root, int curNum){
    if(!root) return 0;
    curNum=curNum*2+root->val;
    if(root->left==root->right) return curNum;
    return dfs(root->left, curNum)+dfs(root->right, curNum);
}

int sumRootToLeaf(struct TreeNode* root) {
    return dfs(root, 0);
}