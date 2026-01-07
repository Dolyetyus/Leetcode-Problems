int updateTree(struct TreeNode* root) {
    if (root == NULL) return 0;

    int leftSum  = updateTree(root->left);
    int rightSum = updateTree(root->right);

    root->val += leftSum + rightSum;

    return root->val;
}

void findMaxProduct(struct TreeNode* root, long long *max, int total) {
    if (root == NULL) return;

    long long product = (long long)(total-root->val) * root->val;
    if (product > *max) *max = product;

    findMaxProduct(root->left, max, total);
    findMaxProduct(root->right, max, total);
}

int maxProduct(struct TreeNode* root) {
    long long ret = 0;
    updateTree(root);
    findMaxProduct(root, &ret, root->val);

    return (int)(ret%1000000007);
}
