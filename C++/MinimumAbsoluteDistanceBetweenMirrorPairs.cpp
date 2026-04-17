class Solution {
public:
    int reverseNum(int x) {
        int num = 0;
        while (x > 0) {
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> lastSeen;
        int ret = INT_MAX;

        for (int j = 0; j<nums.size(); j++) {
            int rev = reverseNum(nums[j]);

            if (lastSeen.count(nums[j])) ret = min(ret, j-lastSeen[nums[j]]);

            lastSeen[rev] = j;
        }

        return ret == INT_MAX ? -1 : ret;
    }
};
