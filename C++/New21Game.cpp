class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k==0 || n>=k+maxPts-1) return 1;

        vector<double> dp(n+1, 0);
        dp[0]=1;
        double wsum=1, prob=0;

        for (int l=0, r=1; r<=n; r++) {
            dp[r]=wsum/maxPts;
            (r<k) ? wsum+=dp[r] : prob+=dp[r];

            if (r>=maxPts) wsum-=dp[l++];
        }
        
        return prob;
    }
};
