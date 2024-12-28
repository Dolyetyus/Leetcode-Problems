class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hmap;
        vector<int> ret;

        for (int num: nums1) {
            hmap[num]++;
        }

        for (int num : nums2) {
            if (hmap[num] > 0) {
                ret.push_back(num);
                hmap[num]--;
            }
        }

        return ret;
    }
};
