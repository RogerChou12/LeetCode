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

 struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // 'p' and 'q' are in the left subtree
    if((root->val > p->val) && (root->val > q->val)){
        return lowestCommonAncestor(root->left, p, q);
    }
    // 'p' and 'q' are in the right subtree
    else if((root->val < p->val) && (root->val < q->val)){
        return lowestCommonAncestor(root->right, p, q);
    }
    
    return root;
}