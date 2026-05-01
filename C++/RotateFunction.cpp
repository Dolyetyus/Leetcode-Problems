class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        auto F = [&](vector<int>& arr) {
            long f = 0;
            for (int i = 0; i < arr.size(); i++)
                f += i*arr[i];
            return f;
        };

        int n = nums.size();
        long total = 0;

        for (int x: nums) total += x;

        vector<long> dp;
        dp.push_back(F(nums));

        for (int i = 1; i<n; i++) {
            long curr = dp[i-1] + total - (long)n*nums[n-i];
            dp.push_back(curr);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
