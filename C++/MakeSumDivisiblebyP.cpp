class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int num : nums) total += num;

        int modulo = total % p;
        if (modulo == 0) return 0;

        unordered_map<int, int> prefix;
        prefix[0] = -1;

        long long prefix_sum = 0;
        int min_len = nums.size();
        for (int i = 0; i<nums.size(); i++) {
            prefix_sum += nums[i];
            int current_mod = prefix_sum % p;
            int target_mod = (current_mod - modulo + p) % p;

            if (prefix.count(target_mod)) min_len = min(min_len, i - prefix[target_mod]);

            prefix[current_mod] = i;
        }

        return min_len == nums.size() ? -1 : min_len;
    }
};
