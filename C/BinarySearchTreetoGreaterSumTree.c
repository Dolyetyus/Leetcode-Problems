void GST(struct TreeNode* root, int *sum){
    if (root==NULL) return;

    GST(root->right, sum);
    (*sum) += root->val;
    root->val = (*sum);
    GST(root->left, sum);
}

struct TreeNode* bstToGst(struct TreeNode* root) {
    struct TreeNode* ret = root;
    int sum = 0;
    GST(root, &sum);
    return ret;
}
