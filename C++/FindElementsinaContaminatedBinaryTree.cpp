class FindElements {
public:
    set<int> st;

    FindElements(TreeNode* root) {
        recover(root);
    }

    void recover(TreeNode* root) {
        if (!root) return;
        if (root->val == -1) {
            root->val = 0;
            st.insert(0);
        }

        if (root->left) {
            root->left->val = 2*root->val+1;
            st.insert(2*root->val+1);
        }
        if (root->right) {
            root->right->val = 2*root->val+2;
            st.insert(2*root->val+2);
        }

        recover(root->left);
        recover(root->right);
    }
    
    bool find(int target) {
        return st.contains(target);
    }
};
