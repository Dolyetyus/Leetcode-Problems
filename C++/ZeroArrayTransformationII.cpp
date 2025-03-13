class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        bool isAllZero = true;
        for (int num: nums){
            if (num!=0){
                isAllZero = false;
                break;
            }
        }

        if (isAllZero) return 0;

        int n = nums.size();
        int q = queries.size();
        
        auto canZero = [&](int k) -> bool {
            vector<long long> diff(n + 1, 0);
            for (int i = 0; i < k; i++) {
                int l = queries[i][0];
                int r = queries[i][1];
                int val = queries[i][2];
                
                diff[l] += val;
                if (r + 1 < n) diff[r + 1] -= val;
            }
            long long capacity = 0;
            for (int i = 0; i < n; i++) {
                capacity += diff[i];
                if (capacity < nums[i]) return false;
            }
            return true;
        };

        int lo = 1, hi = q;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canZero(mid)) {
                ans = mid;
                hi = mid - 1;
            } 
            else lo = mid + 1;
        }
        return ans;
    }
};
