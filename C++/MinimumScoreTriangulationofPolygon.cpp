class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size(); vector<vector<int>> dp(n,vector<int>(n));

        for (int l = 3; l<=n; l++) {
            for (int i = 0; i+l-1<n; i++) {
                int j=i+l-1;
                dp[i][j]=1e9;
                for (int k = i+1; k<j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+v[i]*v[j]*v[k]);
                }
            }
        }

        return dp[0][n-1];
    }
};
