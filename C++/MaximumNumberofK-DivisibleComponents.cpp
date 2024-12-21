class Solution {
public:
    void dfs(int node, int parent, const vector<vector<int>>& adj, const vector<int>& values, int k, long long& count, long long& current_sum) {
        current_sum += values[node];
        for (int neighbor: adj[node]) {
            if (neighbor == parent) continue;
            long long subtree_sum = 0;
            dfs(neighbor, node, adj, values, k, count, subtree_sum);
            current_sum += subtree_sum;
        }
        
        if (current_sum % k == 0) {
            count++;
            current_sum = 0;
        }
    }

    long long maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        long long ret = 0;
        long long current_sum = 0;
        dfs(0, -1, adj, values, k, ret, current_sum);
        
        return ret;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
