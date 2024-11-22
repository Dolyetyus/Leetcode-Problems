class Solution {
public:
    string toString(vector<int> int_array) {
        string returnstring = "";
        for (int i = 0; i < int_array.size(); i++)
            returnstring += to_string(int_array.at(i));
        return returnstring;
    }

    vector<int> reverseMatrix(vector<int> arr) {
        for (int i = 0; i < arr.size(); i++)
            arr.at(i) ^= 1;
        return arr;
    }

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> hmap;
        int ret = 0;

        for (int i = 0; i<matrix.size(); i++){
            if (matrix.at(i).at(0) != 0) matrix.at(i) = reverseMatrix(matrix.at(i));
            string key = toString(matrix.at(i));
            hmap[key]++;
            ret = max(ret, hmap[key]);
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
