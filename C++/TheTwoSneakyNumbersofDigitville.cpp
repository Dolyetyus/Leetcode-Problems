class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ret;
        vector<int> freq(nums.size(), 0);

        for (int num: nums) {
            freq[num]++;
            if (freq[num]>1) ret.push_back(num);
        }

        return ret;
    }
};
