class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int retSize = 1;
        for (int i = 1; i<=nums.size(); i++){
            retSize *= i;
        }
        vector<vector<int>> ret(retSize);
        sort(nums.begin(), nums.end());

        int i = 1;
        ret.at(0) = nums;
        while (next_permutation(nums.begin(), nums.end())){
            ret.at(i) = nums;
            i++;
        }

        return ret;
    }
};
