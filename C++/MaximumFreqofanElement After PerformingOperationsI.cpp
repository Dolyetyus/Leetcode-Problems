class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> mp;
        int freq = 0, ans = 0;

        for (int num: nums) mp[num]++;

        auto i = mp.begin(), j = mp.begin();
        int minVal = mp.begin()->first;
        int maxVal = prev(mp.end())->first;

        for (int it = minVal; it <= maxVal; it++) {
            while (j != mp.end() && j->first <= it + k) {
                freq += j->second;
                j++;
            }

            while (i != mp.end() && i->first < it - k) {
                freq -= i->second;
                i++;
            }

            ans = max(ans, min(mp[it] + numOperations, freq));
        }

        return ans;
    }
};
