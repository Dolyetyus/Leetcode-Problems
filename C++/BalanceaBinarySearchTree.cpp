class Solution {
public:
    vector<int> arr;

    void dfs(TreeNode* root) {
        if (root == NULL) return;

        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }

    TreeNode* buildBST(const vector<int>& arr, int left, int right) {
        if (left > right) return nullptr;

        int mid = left+(right-left) / 2;

        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildBST(arr, left, mid-1);
        root->right = buildBST(arr, mid+1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);

        root = new TreeNode(arr.at(arr.size()/2));
        TreeNode* ret = root;

        return buildBST(arr, 0, arr.size()-1);
    }
};
