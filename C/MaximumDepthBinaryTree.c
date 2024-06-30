int maxDepth(struct TreeNode* root) {
    if(root == NULL) return 0;
    
    int maxLeft = maxDepth(root->left);
    int maxRight = maxDepth(root->right);

    if (maxLeft > maxRight) return maxLeft+1;
    return maxRight+1;
}
