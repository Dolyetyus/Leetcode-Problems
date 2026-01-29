class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = 1e18;
        vector<vector<pair<int, int>>> graph(26);

        for (int i = 0; i<original.size(); i++) {
            int u = original[i]-'a';
            int v = changed[i]-'a';
            graph[u].push_back({v, cost[i]});
        }

       vector<vector<long long>> dist(26, vector<long long>(26, INF));

        for (int start = 0; start<26; start++) {
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            dist[start][start] = 0;

            pq.push({0, start});
            while (!pq.empty()) {
                auto [currCost, u] = pq.top();
                pq.pop();

                if (currCost > dist[start][u]) continue;

                for (auto &[v, w]: graph[u]) {
                    long long newCost = currCost+w;
                    if (newCost<dist[start][v]) {
                        dist[start][v] = newCost;
                        pq.push({newCost, v});
                    }
                }
            }
        }

        long long ret = 0;
        for (int i = 0; i<source.size(); i++) {
            int s = source[i]-'a';
            int t = target[i]-'a';

            if (s == t) continue;
            if (dist[s][t] == INF) return -1;

            ret += dist[s][t];
        }

        return ret;
    }
};
