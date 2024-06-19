class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> sorted;
        int id1 = 0;
        int id2 = 0;

        while (id1 < m && id2 < n) {
            if (nums1[id1] <= nums2[id2]) {
                sorted.push_back(nums1[id1]);
                id1++;
            } 
            else {
                sorted.push_back(nums2[id2]);
                id2++;
            }
        }

        while (id1 < m) {
            sorted.push_back(nums1[id1]);
            id1++;
        }

        while (id2 < n) {
            sorted.push_back(nums2[id2]);
            id2++;
        }

        nums1 = sorted;
    }
};
