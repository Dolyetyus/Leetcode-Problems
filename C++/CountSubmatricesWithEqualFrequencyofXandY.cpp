class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ret = 0;
        int rows = grid.size(), cols = grid[0].size();
        
        vector<int> diff(cols, 0);
        vector<int> hasX(cols, 0);

        for (int i = 0; i < rows; i++) {
            int rowDiff = 0;
            int rowHasX = 0;

            for (int j = 0; j<cols; j++) {
                if (grid[i][j] == 'X') {
                    rowDiff++;
                    rowHasX = 1;
                } 
                else if (grid[i][j] == 'Y') rowDiff--;

                diff[j] += rowDiff;
                hasX[j] |= rowHasX;

                if (hasX[j] && diff[j] == 0) ret++;
            }
        }

        return ret;
    }
};
