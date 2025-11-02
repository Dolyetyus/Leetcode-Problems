class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n));

        for (vector<int> guard: guards) grid[guard[0]][guard[1]] = 1;
        for (vector<int> wall: walls) grid[wall[0]][wall[1]] = 8;
        
        for (int x = 0; x<m; x++) {
            for (int y = 0; y<n; y++) {
                if (grid[x][y] == 1) {
                    for (int i = x-1; i>=0; i--) {
                        if (grid[i][y] == 8 || grid[i][y] == 1) break;
                        grid[i][y] = 5;
                    }

                    for (int i = x+1; i<m; i++) {
                        if (grid[i][y] == 8 || grid[i][y] == 1) break;
                        grid[i][y] = 5;
                    }

                    for (int i = y-1; i>=0; i--) {
                        if (grid[x][i] == 8 || grid[x][i] == 1) break;
                        grid[x][i] = 5;
                    }

                    for (int i = y+1; i<n; i++) {
                        if (grid[x][i] == 8 || grid[x][i] == 1) break;
                        grid[x][i] = 5;
                    }
                }
            }
        }

        int ret = 0;
        for (vector<int> row: grid) {
            for (int el: row) {
                if (el==0) ret++;
            }
        }

        return ret;
    }
};
