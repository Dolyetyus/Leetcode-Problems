class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> freqh(n+1, vector<int>(n+1));
        vector<vector<int>> ret(n, vector<int>(n));

        for (vector<int> query: queries) {
            for (int y = query[0]; y<=query[2]; y++) {
                freqh[y][query[1]]++;
                freqh[y][query[3]+1]--;
            }
        }
        
        for (int i = 0; i<n; i++) {
            int sum = 0;
            for (int ii = 0; ii<n; ii++) {
                sum += freqh[i][ii];
                ret[i][ii] += sum;
            }
        }

        return ret;
    }
};
