class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> hmap;
        int maxFreq = -31;
        int dominantNum = -31;

        for (int num: nums) hmap[num]++;

        for (auto el: hmap){
            if (el.second>maxFreq) {
                maxFreq = el.second;
                dominantNum = el.first;
            }
        }

        int curr = 0;
        for (int i = 1; i<nums.size()+1; i++){
            if (nums.at(i-1) == dominantNum) curr++;
            if (curr>(i-curr) && (maxFreq-curr > ((nums.size()-i)/2))) return i-1;
        }

        return -1;
    }
};
