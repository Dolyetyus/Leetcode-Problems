class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            long long pointsIfSolved = questions[i][0];
            int nextIndex = i + questions[i][1] + 1;
            if (nextIndex < n) pointsIfSolved += dp[nextIndex];
            long long pointsIfSkipped = dp[i + 1];
            
            dp[i] = max(pointsIfSolved, pointsIfSkipped);
        }
        
        return dp[0];
    }
};
