class Solution {
public:
    /* Results in Time Limit Exceeded: 
    int calculateDepth(TreeNode* root, int query, int currentDepth, int& maxDepth) {
        if (root == NULL || root->val == query) 
            return currentDepth - 1;

        maxDepth = max(maxDepth, currentDepth);

        calculateDepth(root->left, query, currentDepth + 1, maxDepth);
        calculateDepth(root->right, query, currentDepth + 1, maxDepth);

        return maxDepth;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ret;

        for (int i = 0; i<queries.size(); i++){
            int depth = 0;
            ret.push_back(calculateDepth(root, queries.at(i), 0, depth));
        }

        return ret;
    }
    */

    map<int, int> l, r, h;
    int height (TreeNode *root)
    {
        if(!root) return 0;
        int lh = height (root->left);
        int rh = height (root->right);
        l[root->val] = lh;
        r[root->val] = rh;
        return max(lh, rh)+1;
    }
    void solve(TreeNode *root, int maxa, int depth)
    {
        if(!root) return;
        h[root->val] = maxa;
        solve(root->left, max(maxa, depth+r[root->val]), depth+1);
        solve(root->right, max(maxa, depth+l[root->val]), depth+1);
    }
    vector<int> treeQueries (TreeNode* root, vector<int>& q)
    {
        height (root);
        solve(root->left, r[root->val], 1);
        solve(root->right, l[root->val], 1);
        vector<int> ans;
        for (int i=0; i<q.size(); i++) ans.push_back(h[q[i]]);
        return ans;
    }
};
