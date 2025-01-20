class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numRows = mat.size();
        int numCols = mat[0].size();
        
        unordered_map<int, pair<int, int>> positionMap;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                positionMap[mat[i][j]] = {i, j};
            }
        }
        
        vector<int> rowCount(numRows, 0);
        vector<int> colCount(numCols, 0);

        for (int i = 0; i < arr.size(); ++i) {
            auto [row, col] = positionMap[arr[i]];
            ++rowCount[row];
            ++colCount[col];

            if (rowCount[row] == numCols || colCount[col] == numRows) {
                return i;
            }
        }

        return 0;
    }

    /* 1057/1058 Time limit exceeded lmao
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numcol = mat.at(0).size();
        int numrow = mat.size();
        vector<int> colmap(numcol, 0);
        vector<int> rowmap(numrow, 0);
        vector<unordered_set<int>> cols;
        vector<unordered_set<int>> rows;

        for (int i = 0; i<numcol; i++){
            unordered_set<int> col;
            for (int ii = 0; ii<numrow; ii++){
                col.insert(mat.at(ii).at(i));
            }
            cols.push_back(col);
        }

        for (int i = 0; i<numrow; i++){
            unordered_set<int> row;
            for (int ii = 0; ii<numcol; ii++){
                row.insert(mat.at(i).at(ii));
            }
            rows.push_back(row);
        }

        for (int ret = 0; ret<arr.size(); ret++){
            for (int i = 0; i<numcol; i++){
                if (cols.at(i).contains(arr[ret])) {
                    colmap[i]++;
                    if (colmap.at(i)==numrow) return ret;
                }
            }
            for (int i = 0; i<numrow; i++){
                if (rows.at(i).contains(arr[ret])) {
                    rowmap[i]++;
                    if (rowmap.at(i)==numcol) return ret;
                }
            }
        }

        return 0;
    }*/
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
