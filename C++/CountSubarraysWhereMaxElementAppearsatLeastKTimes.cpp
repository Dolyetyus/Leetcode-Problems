class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maks = 0;
        for (int num: nums) maks = max(num, maks);

        int left = 0, count = 0;
        long long ret = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == maks) count++;

            while (count >= k) {
                ret += nums.size() - right;
                if (nums[left] == maks) count--;
                left++;
            }
        }
        
        return ret;
    }
};
