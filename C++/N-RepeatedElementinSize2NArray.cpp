class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> hmap;

        for (int num: nums) {
            if (hmap.count(num)) return num;
            hmap.insert(num);
        }

        return 0;
    }
};
