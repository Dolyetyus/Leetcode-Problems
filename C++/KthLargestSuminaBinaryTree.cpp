class Solution {
public:
    void traverse(TreeNode* root, vector<long long>& sums, int depth){
        if (root==NULL) 
            return;
        if (sums.size()<depth)
            sums.push_back(0);

        traverse(root->left, sums, depth+1);
        sums[depth-1] += root->val;
        traverse(root->right, sums, depth+1);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums;
        traverse(root, sums, 1);
    
        if (k-1>=sums.size()) 
            return -1;
        sort(sums.begin(), sums.end(), greater<>());
        return sums[k-1];
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
