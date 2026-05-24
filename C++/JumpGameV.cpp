class Solution {
public:
        int dfs(vector<int>& arr, int index, int d, vector<int>& dp){
        if (dp[index] != -1) return dp[index];
        dp[index] = 1;

        for (int i = index-1; i >= index-d && i >= 0; i--){
            if(arr[i] >= arr[index]) break;
            dp[index] = max(dp[index], dfs(arr, i, d, dp) + 1);
        }

        for (int i = index+1; i <= index+d && i < arr.size(); i++){
            if(arr[i] >= arr[index]) break;
            dp[index] = max(dp[index], dfs(arr, i, d, dp) + 1);
        }

        return dp[index];
    }

    int maxJumps(vector<int>& arr, int d) {
        vector<int> dp(arr.size(), -1);
        int maxJump = 0;

        for (int i = 0; i<arr.size(); i++){
            maxJump = max(maxJump, dfs(arr, i, d, dp));
        }

        return maxJump;
    }
};
