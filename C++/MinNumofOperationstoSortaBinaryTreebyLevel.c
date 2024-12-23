class Solution {
public:
    void dfs(TreeNode* root, int level, unordered_map<int, vector<int>> &hmap){
        if (root==NULL) return;

        hmap[level].push_back(root->val);
        dfs(root->left, level+1, hmap);
        dfs(root->right, level+1, hmap);
    }

    int minSwapsToSort(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> arrWithIndex(n);
        for (int i = 0; i < n; ++i) {
            arrWithIndex[i] = {arr[i], i};
        }

        sort(arrWithIndex.begin(), arrWithIndex.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || arrWithIndex[i].second == i) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = arrWithIndex[j].second;
                ++cycleSize;
            }

            if (cycleSize > 1) swaps += (cycleSize - 1);
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        unordered_map<int, vector<int>> hmap;

        dfs(root, 0, hmap);

        int ret = 0;
        for (auto entry: hmap){
            ret += minSwapsToSort(entry.second);
        }

        return ret;
    }
};
