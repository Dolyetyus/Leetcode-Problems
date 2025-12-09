class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> total;
        unordered_map<int, int> left;
        int ret = 0;

        left[nums[0]]++;
        for (int num: nums) total[num]++;

        for (int i = 1; i<nums.size()-1; i++) {
            int seek = nums[i]*2;
            long long bef = left[seek];
            long long aft = total[seek]-left[seek];
            if (seek == nums[i]) aft--;
            if (bef*aft>0) {
                ret += ((bef*aft)%1000000007);
                ret %= 1000000007;
            }
            left[nums[i]]++;
        }

        return ret;
    }
};
