class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> dset;

        for (int num: nums) {
            dset.insert(num);
        }

        int distinct = dset.size();

        int left = 0;
        int count = 0;
        int ret = 0;
        unordered_map<int, int> freq; 
        for (int right = 0; right < nums.size(); ++right) {
            if (freq[nums[right]]++ == 0) {
                ++count;
            }
            while (count == distinct) {
                ret += nums.size() - right;
                if (--freq[nums[left]] == 0) --count;
                ++left;
            }
        }

        return ret;
    }
};
