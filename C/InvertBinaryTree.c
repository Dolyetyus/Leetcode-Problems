void helper(struct TreeNode* root){
    if (root==NULL) return;

    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    helper(root->left);
    helper(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root) {
    helper(root);
    return root;
}
