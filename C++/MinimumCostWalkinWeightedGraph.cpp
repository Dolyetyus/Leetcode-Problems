class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> component;
    vector<int> minAndValue;

    void dfs(int node, int compId, int& andValue) {
        component[node] = compId;
        for (auto& [neighbor, weight] : adj[node]) {
            andValue &= weight;
            if (component[neighbor] == -1) {
                dfs(neighbor, compId, andValue);
            }
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        adj.resize(n);
        component.assign(n, -1);
        minAndValue.assign(n, INT_MAX);
        
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int compId = 0;
        for (int i = 0; i < n; i++) {
            if (component[i] == -1) {
                int andValue = INT_MAX;
                dfs(i, compId, andValue);
                minAndValue[compId] = andValue;
                compId++;
            }
        }

        vector<int> res;
        for (auto& q : queries) {
            int s = q[0], t = q[1];
            if (component[s] != component[t]) res.push_back(-1);
            else res.push_back(minAndValue[component[s]]);
        }
        
        return res;
    }
};
