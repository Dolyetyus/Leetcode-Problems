class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0;
        vector<int> r1, r2;

        for (int num: nums) {
            total += num;
            if (num % 3 == 1) r1.push_back(num);
            else if (num % 3 == 2) r2.push_back(num);
        }

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        if (total % 3 == 0) return total;

        int rem = total % 3;
        int ret = 0;
        if (rem == 1) {
            int remove1 = r1.size() > 0 ? r1[0] : INT_MAX;
            int remove2 = r2.size() > 1 ? r2[0] + r2[1] : INT_MAX;
            ret = total - min(remove1, remove2);
        } 
        else {
            int remove1 = r2.size() > 0 ? r2[0] : INT_MAX;
            int remove2 = r1.size() > 1 ? r1[0] + r1[1] : INT_MAX;
            ret = total - min(remove1, remove2);
        }

        return ret == INT_MAX ? 0 : ret;
    }
};
