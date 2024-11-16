class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ret;
        for (int i = 0; i<nums.size()-k+1; i++){
            bool is_con = true;
            for (int ii = 0; ii<k-1; ii++){ 
                if (nums.at(i+ii)+1 != nums.at(i+ii+1)) { 
                    is_con = false; 
                    break;
                }
            }

            if (is_con)
                ret.push_back(nums.at(i+k-1));
            else
                ret.push_back(-1);
        }
        return ret;
    }
};
