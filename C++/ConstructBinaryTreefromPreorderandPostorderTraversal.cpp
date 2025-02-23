class Solution {
public:
    int pre_idx=0;
    int post_idx=0;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root=new TreeNode(preorder[pre_idx++]);
        if (root->val != postorder[post_idx])
            root->left = constructFromPrePost(preorder,postorder);

        if (root->val != postorder[post_idx])
            root->right = constructFromPrePost(preorder,postorder);

        post_idx++;
        return root;
    }
};
