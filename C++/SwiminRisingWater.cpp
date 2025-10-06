class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    void dfs (vector<vector<int>>& grid, vector<vector<bool>>& visited, unordered_map<pair<int, int>, int, pair_hash>& hmap, pair<int, int> coordinates, int currentMax) {
        int n = grid.size();
        int x = coordinates.first, y = coordinates.second;

        if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y]) return;

        currentMax = max(currentMax, grid[x][y]);

        if (hmap.find({x, y}) != hmap.end() && hmap[{x, y}] <= currentMax) return;

        hmap[{x, y}] = currentMax;
        visited[x][y] = true;

        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (pair<int, int> d: dirs) {
            int nx = x + d.first;
            int ny = y + d.second;
            dfs(grid, visited, hmap, {nx, ny}, currentMax);
        }

        visited[x][y] = false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<pair<int, int>, int, pair_hash> hmap;     // pair<x, y>, minmax
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        dfs(grid, visited, hmap, {0, 0}, grid.at(0).at(0));

        return hmap[{n-1, n-1}];
    }
};
