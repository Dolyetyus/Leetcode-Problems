class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> stack;
        int ret = 0;

        for (int num: nums) {
            while (!stack.empty() && stack.back() > num) {
                stack.pop_back();
            }
            
            if (num == 0) continue;
            if (stack.empty() || stack.back() < num) {
                ret++;
                stack.push_back(num);
            }
        }

        return ret;
    }
};
