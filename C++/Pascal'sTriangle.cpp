class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.push_back({1});

        for (int i = 0; i<numRows-1; i++){
            vector<int> row;
            int n = ret.at(i).size();
            row.push_back(ret.at(i).at(0));

            for (int ii = 1; ii<n; ii++) row.push_back(ret.at(i).at(ii)+ret.at(i).at(ii-1));

            row.push_back(ret.at(i).at(n-1));
            ret.push_back(row);
        }

        return ret;
    }
};
