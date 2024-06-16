class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& visited, int m, int n, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        dfs(i + 1, j, visited, m, n, grid);
        dfs(i - 1, j, visited, m, n, grid);
        dfs(i, j + 1, visited, m, n, grid);
        dfs(i, j - 1, visited, m, n, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ysize = grid.size();
        if (ysize == 0) return 0;
        int xsize = grid[0].size();

        vector<vector<bool>> visited(ysize, vector<bool>(xsize, false));

        int island_count = 0; 
        for (int i = 0; i < ysize; ++i) {
            for (int j = 0; j < xsize; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    island_count++;
                    dfs(i, j, visited, ysize, xsize, grid);
                }
            }
        }

        return island_count;
    }
};
