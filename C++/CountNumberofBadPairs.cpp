class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> hmap;
        long long ret = 0;
        long long total = nums.size()*(nums.size()-1)/2;

        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i]-i;
            ret += hmap[key]; 
            hmap[key]++;
        }

        return total-ret;
    }
};
