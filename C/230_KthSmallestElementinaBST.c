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

void search(struct TreeNode *root, int *k, int *ans){
    if(!root || (*k)==0) return;
    search(root->left, k, ans);

    (*k)--;
    if((*k)==0){
        (*ans) = root->val;
    }
    search(root->right, k, ans);
}

int kthSmallest(struct TreeNode* root, int k) {
    int ans=-1;
    search(root, &k, &ans);
    return ans;
}