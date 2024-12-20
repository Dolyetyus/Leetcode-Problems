void reverse(struct TreeNode* left, struct TreeNode* right, int depth) {
    if (left == NULL || right == NULL) return;

    if (depth % 2 == 1) {
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
    }

    reverse(left->left, right->right, depth+1);
    reverse(left->right, right->left, depth+1);
}

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    struct TreeNode* ret = root;
    reverse(root->left, root->right, 1);
    return root;
}
