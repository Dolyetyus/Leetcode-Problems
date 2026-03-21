class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = y; i<y+k; i++) {
            for (int ii = 0; ii<k/2; ii++) {
                swap(grid[x+ii][i], grid[x+k-1-ii][i]);
            }
        }

        return grid;
    }
};
