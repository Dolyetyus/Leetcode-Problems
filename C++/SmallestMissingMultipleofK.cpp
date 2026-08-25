class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> seen(n+2, false);

        for (int i: nums) {
            if (i%k == 0) {
                int multiple = i/k;
                if (multiple <= n+1) seen[multiple] = true;
            }
        }

        for (int multiple = 1; multiple <= n+1; multiple++) {
            if (!seen[multiple]) return multiple*k;
        }

        return -1;
    }
};
