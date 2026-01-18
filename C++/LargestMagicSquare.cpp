class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> rowPS(m, vector<int>(n+1, 0));
        vector<vector<int>> colPS(m+1, vector<int>(n, 0));
        vector<vector<int>> diag1(m+1, vector<int>(n+1, 0));
        vector<vector<int>> diag2(m+1, vector<int>(n+1, 0));

        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                rowPS[i][j+1] = rowPS[i][j] + grid[i][j];
                colPS[i+1][j] = colPS[i][j] + grid[i][j];
                diag1[i+1][j+1] = diag1[i][j] + grid[i][j];
                diag2[i+1][j] = diag2[i][j+1] + grid[i][j];
            }
        }

        int maxK = min(m, n);

        for (int k = maxK; k >= 2; k--) {
            for (int r = 0; r+k <= m; r++) {
                for (int c = 0; c+k <= n; c++) {
                    int target = rowPS[r][c+k] - rowPS[r][c];
                    bool ok = true;

                    for (int i = r; i < r+k && ok; i++) {
                        if (rowPS[i][c+k] - rowPS[i][c] != target) ok = false;
                    }

                    for (int j = c; j < c+k && ok; j++) {
                        if (colPS[r+k][j] - colPS[r][j] != target) ok = false;
                    }

                    if (ok) {
                        int d1 = diag1[r+k][c+k] - diag1[r][c];
                        int d2 = diag2[r+k][c] - diag2[r][c+k];
                        if (d1 != target || d2 != target) ok = false;
                    }

                    if (ok) return k;
                }
            }
        }

        return 1;
    }
};
