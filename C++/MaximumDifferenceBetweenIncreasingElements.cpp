class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ret = -1;
        int curr = 1999999999;

        for (int num: nums){
            if (num<curr) curr = num;
            if (num-curr > ret) ret=num-curr;
        }

        if (!ret) return -1;
        return ret;
    }
};
