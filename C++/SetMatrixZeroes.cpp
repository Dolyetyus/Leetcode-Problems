class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;

        for (int i = 0; i<matrix.size(); i++) {
            for (int ii = 0; ii<matrix.at(0).size(); ii++) {
                if (matrix.at(i).at(ii) == 0) {
                    rows.insert(i);
                    cols.insert(ii);
                }
            }
        }

        for (int r: rows) {
            if (r >= 0 && r < matrix.size()) {
                for (int j = 0; j < matrix[0].size(); ++j) matrix[r][j] = 0;
            }
        }

        for (int c: cols) {
            if (!matrix.empty() && c >= 0 && c < matrix[0].size()) {
                for (int i = 0; i < matrix.size(); ++i) matrix[i][c] = 0;
            }
        }
    }
};
