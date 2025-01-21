class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefixTop(n+1, 0), prefixBottom(n+1, 0);

        for (int i = n - 1; i >= 0; --i) {
            prefixTop[i] = prefixTop[i+1] + grid[0][i];
            prefixBottom[i] = prefixBottom[i+1] + grid[1][i];
        }

        long long ret = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            long long topRemaining = prefixTop[i+1];
            long long bottomRemaining = prefixBottom[0] - prefixBottom[i];
            
            long long secondRobotPoints = max(topRemaining, bottomRemaining);
            ret = min(ret, secondRobotPoints);
        }

        return ret;
    }

    /*long long gridGame(vector<vector<int>>& grid) {
        vector<vector<int>> prefix = grid;

        for (int i = prefix[0].size()-2; i>=0; i--){
            prefix[0][i] += prefix[0][i+1];
            prefix[1][i] += prefix[1][i+1];
        }

        int x = 0, y = 0;
        while (x<grid[0].size()){
            if (y==1){
                for (int i = x; i<grid[0].size(); i++)
                    grid[y][i] = 0;
                break;
            }

            grid[y][x] = 0;
            if (x==grid[0].size()-1){
                grid[1][x] = 0;
                break;
            }

            if (prefix[y][x+1]>prefix[y+1][x]) x++;
            else y++;
        }

        prefix = grid;
        for (int i = prefix[0].size()-2; i>=0; i--){
            prefix[0][i] += prefix[0][i+1];
            prefix[1][i] += prefix[1][i+1];
        }

        x = 0, y = 0;
        long long ret = 0;
        while (x < prefix[0].size()) {
            if (y == 1) {
                ret += prefix[y][x];
                break;
            }

            if (x + 1 < prefix[0].size() && prefix[y][x + 1] > prefix[y + 1][x]) x++;
            else {
                ret += prefix[y][x] - prefix[y][0];
                y++;
            }
        }

        return ret;
    }*/
};
