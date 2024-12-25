class Solution {
public:
    /* DFS, my beloved fav graph traversal - but slow in this problem :( 
    void dfs(TreeNode* root, int level, map<int, vector<int>> &hmap){
        if (root==NULL) return;

        hmap[level].push_back(root->val);
        dfs(root->left, level+1, hmap);
        dfs(root->right, level+1, hmap);
    }

    vector<int> largestValues(TreeNode* root) {
        map<int, vector<int>> hmap;
        dfs(root, 0, hmap);

        vector<int> ret;
        for (auto elem: hmap){
            int max = INT_MIN;
            for (int num: elem.second){
                if (num>max) max = num;
            }
            ret.push_back(max);
        }
        return ret;
    } */
    
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) return {};

        vector<int> ret;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int maxVal = INT_MIN;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (current->val > maxVal) maxVal = current->val;

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            ret.push_back(maxVal);
        }

        return ret;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
