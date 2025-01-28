class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] <= 0)
            return 0;

        int ret = grid[x][y];
        grid[x][y] = -1;

        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (vector<int> dir : dirs) {
            int newX = x+dir[0];
            int newY = y+dir[1];
            ret += dfs(grid, newX, newY);
        }

        return ret;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int ret = 0;

        for (int i = 0; i<grid.size(); i++){
            for (int ii = 0; ii<grid.at(0).size(); ii++){
                if (grid[i][ii] != 0)
                    ret = max(ret, dfs(grid, i, ii));
            }
        }

        return ret;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
