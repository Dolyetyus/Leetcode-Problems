class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int distinct = 0;
        long long lastUsed = LLONG_MIN;

        for (int num: nums) {
            long long low = (long long)num - k;
            long long high = (long long)num + k;

            if (high > lastUsed) {
                long long assign = max(low, lastUsed + 1);
                lastUsed = assign;
                distinct++;
            }
        }

        return distinct;
    }

    /* TLE 631 / 633 lol
    int maxDistinctElements(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num: nums) freq[num]++;
        
        vector<int> uniqueNums;
        for (auto& [num, count]: freq) uniqueNums.push_back(num);
        sort(uniqueNums.begin(), uniqueNums.end());
        
        set<int> used;
        for (int num: uniqueNums) {
            int count = freq[num];
            for (int i = num - k; i <= num + k && count > 0; ++i) {
                if (used.find(i) == used.end()) {
                    used.insert(i);
                    count--;
                }
            }
        }
        
        return used.size();
    }
    */
};
