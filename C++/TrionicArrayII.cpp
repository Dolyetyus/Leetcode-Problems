class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        vector<tuple<int, int, int>> seg;
        int i = 0;
        while (i < n - 1) {
            int j = i;
            if (nums[j+1] > nums[j]) {
                while (j+1 < n && nums[j+1] > nums[j]) j++;
                seg.emplace_back(i, j, 1);
            } 
            else if (nums[j+1] < nums[j]) {
                while (j + 1 < n && nums[j + 1] < nums[j]) j++;
                seg.emplace_back(i, j, -1);
            } 
            else {
                seg.emplace_back(i, i+1, 0);
                i++;
                continue;
            }
            i = j;
        }

        long long res = LLONG_MIN;
        for (int i = 0; i + 2 < (int)seg.size(); i++) {
            auto [l1, r1, g1] = seg[i];
            auto [l2, r2, g2] = seg[i+1];
            auto [l3, r3, g3] = seg[i+2];

            if (!(g1 == 1 && g2 == -1 && g3 == 1)) continue;

            long long total = prefix[r2+1]-prefix[l2];

            long long best1 = LLONG_MIN;
            for (int k = l1; k < r1; k++) {
                best1 = max(best1, prefix[r1]-prefix[k]);
            }

            long long best3 = LLONG_MIN;
            for (int k = l3+1; k <= r3; k++) {
                best3 = max(best3, prefix[k+1]-prefix[l3+1]);
            }

            res = max(res, total + best1 + best3);
        }

        return (res == LLONG_MIN ? 0 : res);
    }
};
