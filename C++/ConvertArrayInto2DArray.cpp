class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> hashmap;
        vector<vector<int>> ret;

        for (int i = 0; i<nums.size(); i++){
            hashmap[nums[i]]++;
        }

        while (!hashmap.empty()) {
            vector<int> temp;
            auto it = hashmap.begin();

            while (it != hashmap.end()) {
                temp.push_back(it->first);
                it->second--;

                if (it->second == 0) {
                    it = hashmap.erase(it);
                } 
                else {
                    ++it;
                }
            }
            
            ret.push_back(temp);
        }

        return ret;
    }
};
