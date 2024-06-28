class Solution {
public:
    vector<int> sorted;

    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return sorted;
    }

    void traverse(TreeNode* root){
        if (root == NULL) {
            return;
        }

        sorted.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
};
