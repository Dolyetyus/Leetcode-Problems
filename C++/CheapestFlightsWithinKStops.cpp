class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto& f : flights) {
            graph[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({0, src, 0});

        vector<int> stops(n, INT_MAX);

        while (!pq.empty()) {
            auto [cost, node, k] = pq.top(); pq.pop();
            if (node == dst) return cost;
            if (k > K || k > stops[node]) continue;
            
            stops[node] = k;
            for (auto [nei, price] : graph[node]) {
                pq.push({cost + price, nei, k+1});
            }
        }
        return -1;
    }
};
