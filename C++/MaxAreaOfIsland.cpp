class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& visited, int m, int n, vector<vector<int>>& grid, int& size) {
        if (i < 0 || j < 0 || i>=m || j>=n || grid[i][j] == 0 || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        size++;

        dfs(i + 1, j, visited, m, n, grid, size);
        dfs(i - 1, j, visited, m, n, grid, size);
        dfs(i, j + 1, visited, m, n, grid, size);
        dfs(i, j - 1, visited, m, n, grid, size);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ysize = grid.size();
        if (ysize == 0) return 0;
        int xsize = grid[0].size();

        vector<vector<bool>> visited(ysize, vector<bool>(xsize, false));

        int max_size = 0;
        for (int i = 0; i < ysize; ++i) {
            for (int j = 0; j < xsize; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int size = 0;
                    dfs(i, j, visited, ysize, xsize, grid, size);
                    max_size = max(max_size, size);
                }
            }
        }

        return max_size;
    }
};
