class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = nums.size()-1; i>=2; i--) {
            if (nums[i-2] + nums[i-1] > nums[i]) return nums[i-2] + nums[i-1] + nums[i];
        }

        return 0;
    }
    
    /* TLE lol 80/84
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = nums.size()-1; i>=2; i--) {
            for (int ii = i-1; ii>=1; ii--) {
                for (int iii = ii-1; iii>=0; iii--) {
                    if (nums[i]+nums[ii]>nums[iii] && nums[i]+nums[iii]>nums[ii] && nums[ii]+nums[iii]>nums[i]) return nums[i]+nums[ii]+nums[iii];
                }
            }
        }

        return 0;
    }
    */
};
