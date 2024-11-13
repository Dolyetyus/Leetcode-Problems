class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> matrix;
        for (int i = 0; i<nums.size(); i++){
            matrix.push_back({nums.at(i), i});
        }
        sort(matrix.begin(), matrix.end());

        long long ret = 0;
        int left = 0;
        int right = nums.size()-1;
        int n = nums.size();

        while (left<right){
            int rightLow = left+1;
            int rightHigh = n-1;

            while (rightLow <= rightHigh) {
                int mid = rightLow + (rightHigh-rightLow) / 2;
                if (matrix.at(left).at(0) + matrix.at(mid).at(0) >= lower) rightHigh = mid - 1;
                else rightLow = mid + 1;
            }
            int start = rightLow;

            rightLow = left + 1;
            rightHigh = n - 1;
            while (rightLow <= rightHigh) {
                int mid = rightLow + (rightHigh - rightLow) / 2;
                if (matrix.at(left).at(0) + matrix.at(mid).at(0) <= upper) rightLow = mid + 1;
                else rightHigh = mid - 1;
            }
            int end = rightHigh;

            if (start <= end) ret += end - start + 1;
            left++;
        }

        return ret;
    }
};
