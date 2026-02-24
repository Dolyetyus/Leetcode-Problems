class Solution {
public:
    int ret = 0;

    void dfs(TreeNode* root, int curr) {
        if (root == NULL) return;

        curr = curr*2 + root->val;
        if (root->left == NULL && root->right == NULL) {
            ret += curr;
            return;
        }

        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
};
