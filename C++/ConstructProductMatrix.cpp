class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total = n*m;
        vector<vector<int>> ret(n, vector<int>(m));
        vector<int> prefix(total), suffix(total);

        prefix[0] = grid[0][0] % 12345;
        for (int idx = 1; idx<total; idx++) {
            int i = idx / m;
            int j = idx % m;
            prefix[idx] = ((long long)prefix[idx-1] * grid[i][j]) % 12345;
        }

        suffix[total-1] = grid[n-1][m-1] % 12345;
        for (int idx = total-2; idx>=0; idx--) {
            int i = idx / m;
            int j = idx % m;
            suffix[idx] = ((long long)suffix[idx+1] * grid[i][j]) % 12345;
        }

        for (int idx = 0; idx<total; idx++) {
            int i = idx / m;
            int j = idx % m;

            int left = (idx > 0) ? prefix[idx-1] : 1;
            int right = (idx < total-1) ? suffix[idx+1] : 1;

            ret[i][j] = (left*right) % 12345;
        }

        return ret;
    }
};
