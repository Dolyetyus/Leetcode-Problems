class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> hmap;
        int i = 0, j = 0;

        while (i<nums1.size() || j<nums2.size()){
            if (i<nums1.size() && j<nums2.size()){
                if (hmap[nums1.at(i).at(0)]) hmap[nums1.at(i).at(0)] += nums1.at(i).at(1);
                else hmap[nums1.at(i).at(0)] = nums1.at(i).at(1);

                if (hmap[nums2.at(j).at(0)]) hmap[nums2.at(j).at(0)] += nums2.at(j).at(1);
                else hmap[nums2.at(j).at(0)] = nums2.at(j).at(1);
                i++;
                j++;
            }

            if (i<nums1.size()){
                if (hmap[nums1.at(i).at(0)]) hmap[nums1.at(i).at(0)] += nums1.at(i).at(1);
                else hmap[nums1.at(i).at(0)] = nums1.at(i).at(1);
                i++;
            }

            if (j<nums2.size()){
                if (hmap[nums2.at(j).at(0)]) hmap[nums2.at(j).at(0)] += nums2.at(j).at(1);
                else hmap[nums2.at(j).at(0)] = nums2.at(j).at(1);
                j++;
            }
        }

        vector<vector<int>> ret;
        for (auto el: hmap){
            ret.push_back({el.first, el.second});
        }

        return ret;
    }
};
