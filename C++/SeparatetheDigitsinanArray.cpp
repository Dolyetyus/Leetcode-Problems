class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ret;

        for (int i = nums.size(); i--; i>=0) {
            int num = nums[i];
            while (num>0) {
                ret.push_back(num%10);
                num /= 10;
            }
        }

        for (int i = 0; i<ret.size()/2; i++) {
            int temp = ret[ret.size()-1-i];
            ret[ret.size()-1-i] = ret[i];
            ret[i] = temp;
        }

        return ret;
    }
};
