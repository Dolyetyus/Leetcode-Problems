class Solution {
public:
    map<int, int> hmap;

    void dfs(TreeNode* node, int level) {
        if (node == nullptr) return;

        hmap[level] += node->val;

        dfs(node->left, level+1);
        dfs(node->right, level+1);
    }

    int maxLevelSum(TreeNode* root) {
        int max = INT_MIN;
        int ret = 0;
        dfs(root, 1);

        for (auto& entry: hmap){
            if (entry.second > max) {
                ret = entry.first;
                max = entry.second;
            }
        }

        return ret;
    }
};
