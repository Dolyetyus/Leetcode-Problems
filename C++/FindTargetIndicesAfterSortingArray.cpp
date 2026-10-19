class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ret;
        sort(nums.begin(), nums.end());

        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] == target) ret.push_back(i);
        }

        return ret;
    }
};
