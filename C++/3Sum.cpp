class Solution {
public:
    /*vector<vector<int>> threeSum(vector<int>& nums) {
        set<int> lookup(nums.begin(), nums.end());

        vector<vector<int>> ret;
        for (int i = 0; i<nums.size(); i++){
            int find = 0-nums.at(i);
            for(int ii = i+1; ii<nums.size(); ii++){
                int find2 = find-nums.at(ii);
                if (lookup.contains(find2)){
                    vector<int> temp = {nums.at(i), nums.at(ii), find2};
                    ret.push_back(temp);
                }
            }
        }

        return ret;
    }*/
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums.at(i) == nums.at(i-1)) continue;

            int target = 0-nums.at(i);
            int left = i+1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    ret.push_back({nums.at(i), nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;
                } 
                else if (sum < target) left++;
                else right--;
            }
        }

        return ret;
    }
};
