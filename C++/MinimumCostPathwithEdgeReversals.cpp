class Solution {
public:
    typedef pair<int, int> P;
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>> adj;

        for (auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> result(n, INT_MAX);
        result[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if (node == n-1) return result[n-1];

            for (auto &p: adj[node]){
                int adj_node = p.first;
                int distance = p.second;

                if (distance + d < result[adj_node]) {
                    result[adj_node] = d+distance;
                    pq.push({d+distance, adj_node});
                }
            }
        }

        return -1;
    }
};
