class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> numSet(nums.begin(), nums.end());
        int maxStreak = -1;

        for (int i=0; i<nums.size(); i++) {
            long long current = nums[i];
            int count = 1;

            while (numSet.find(current*current) != numSet.end()) {
                current *= current;
                count++;
            }

            if (count>=2) maxStreak = max(maxStreak, count);
        }

        return maxStreak;
    }
};

auto init = []() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
} ();
