class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ret = 0;
        long long sum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum * (right - left + 1LL) >= k) sum -= nums[left++];
            ret += (right - left + 1);
        }

        return ret;
    }
};
