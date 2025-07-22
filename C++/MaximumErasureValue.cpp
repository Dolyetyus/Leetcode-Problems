class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> hmap;
        int ret = 0;
        int total = 0;
        int right = 0;

        for (int left = 0; left<=right; left++){
            if (left==nums.size()) break;

            while (right<nums.size() && hmap[nums.at(right)]<1) {
                hmap[nums.at(right)]++;
                total += nums.at(right);
                right++;
            }
            if (total>ret) ret = total;
            total -= nums.at(left);
            hmap[nums.at(left)]--;
        }

        return ret;
    }
};
