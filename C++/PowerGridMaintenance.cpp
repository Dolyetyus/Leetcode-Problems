class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        DSU(int n): parent(n + 1), size(n + 1, 1) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }

        void unite(int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    };

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        for (auto &e: connections) dsu.unite(e[0], e[1]);

        unordered_map<int, set<int>> compOnline;
        vector<bool> online(c + 1, true);

        for (int i = 1; i <= c; ++i) compOnline[dsu.find(i)].insert(i);

        vector<int> ret;
        for (auto &q: queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);

            if (type == 2) {
                if (online[x]) {
                    compOnline[root].erase(x);
                    online[x] = false;
                }
            } 
            else if (type == 1) {
                if (online[x]) ret.push_back(x);
                else if (!compOnline[root].empty()) ret.push_back(*compOnline[root].begin());
                else ret.push_back(-1);
            }
        }

        return ret;
    }
};
