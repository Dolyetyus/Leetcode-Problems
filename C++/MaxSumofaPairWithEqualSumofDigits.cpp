class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> tops;
        int ret = -1;

        for (int i=0; i<nums.size(); i++){
            int sum = 0;
            int num = nums.at(i);
            while(num!=0){
                sum += num % 10;
                num = num / 10;
            }

            if (tops[sum]){
                ret = max(tops[sum]+nums.at(i), ret);
            }
            
            if (tops[sum] < nums.at(i)) tops[sum] = nums.at(i);
        }

        return ret;
    }
};
