class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ret = 0;
        int n = nums.size();
        int minPos = -1, maxPos = -1, badPos = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) badPos = i;
            if (nums[i] == minK) minPos = i;
            if (nums[i] == maxK) maxPos = i;

            int start = min(minPos, maxPos);
            if (start > badPos) ret += (start - badPos);
        }

        return ret;
    }
};
