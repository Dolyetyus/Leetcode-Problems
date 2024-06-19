class Solution {
public:
    vector<int> sorted;

    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return sorted;
    }

    void traverse(TreeNode* root){
        if (root == NULL) {
            return;
        }

        traverse(root->left);
        sorted.push_back(root->val);
        traverse(root->right);
    }
};
