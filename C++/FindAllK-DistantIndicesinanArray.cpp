class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ret;
        for (int i = 0; i<nums.size(); i++){
            if (nums.at(i)==key){
                for (int ii = i-k; ii<=i+k; ii++) {
                    if (ii>=0 && ii<nums.size()) ret.insert(ii);
                }
            }
        }

        vector<int> v(ret.begin(), ret.end());
        return v;
    }
};
