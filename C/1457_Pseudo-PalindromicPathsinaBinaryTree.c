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

int paths(struct TreeNode* root, int path){
    if(!root){
        return 0;
    }
    path ^= (1<<root->val); // Keep track of the occurrences of each digit in the current path
    if(!(root->left) && (!root->right)){ // The current node is a leaf
        return (path&(path-1))==0 ? 1:0; // Check the path is pseudo-palindromic
    }
    return paths(root->left, path)+paths(root->right, path);
}

int pseudoPalindromicPaths (struct TreeNode* root) {
    return paths(root, 0);
}