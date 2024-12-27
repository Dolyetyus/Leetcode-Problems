class Solution {
public:
    void GST(TreeNode* root, int& sum) {
        if (root == NULL) return;

        GST(root->right, sum);
        sum += root->val;
        root->val = sum;
        GST(root->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        TreeNode* ret = root;
        int sum = 0;
        GST(root, sum);
        return ret;
    }
};
