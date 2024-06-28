class Solution {
public:
    vector<int> sorted;

    vector<int> postorderTraversal(TreeNode* root) {
        traverse(root);
        return sorted;
    }

    void traverse(TreeNode* root){
        if (root == NULL) {
            return;
        }

        traverse(root->left);
        traverse(root->right);
        sorted.push_back(root->val);
    }
};
