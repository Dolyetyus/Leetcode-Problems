class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> hmap;
        int n = nums[0].size();

        for (string num: nums){
            hmap.insert(num);
        }

        string ret = "";
        for (int i = 0; i<n; i++){
            ret.push_back('0');
        }

        while (hmap.contains(ret)){
            ret[n] = '1';
            n--;
        }

        return ret;
    }
};
