class Solution {
public:
    int helper(int i, int j, int sum, int &k, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if (i<0 || j<0) return 0;
        if (i == 0 && j == 0) return (sum+grid[0][0]) % k == 0;
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        
        int newSum = (sum + grid[i][j]) % k;
        int top = helper(i-1, j, newSum, k, grid, dp);
        int left = helper(i, j-1, newSum, k, grid, dp);
        
        return dp[i][j][sum] = (top+left) % 1000000007;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, -1))
        );

        return helper(m-1, n-1, 0, k, grid, dp);
    }
};
