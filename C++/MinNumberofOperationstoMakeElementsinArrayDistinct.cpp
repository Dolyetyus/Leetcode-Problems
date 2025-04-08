class Solution {
public:
    /*
    int minimumOperations(vector<int>& nums) {
        vector<int> duplicates;
        vector<int> freqArr(101, 0);
        int index = 0;

        for (int num: nums) freqArr.at(num)++;
        for (int i = 0; i<100; i++) {
            if (freqArr.at(i)>1) {
                duplicates.push_back(i);
                index++;
            }
        }
        if (index==0) return 0;

        int i = 0;
        int numsIndex = 0;
        int ret = 0;
        while (freqArr.at(duplicates.at(index-1)) > 1){
            while (freqArr.at(duplicates.at(i)) > 1){
                ret++;
                for (int n = 0; n<3; n++) {
                    for (int num: duplicates){
                        cout<<num<<" "<<freqArr.at(num)<<endl;
                    }
                    freqArr.at(nums.at(numsIndex))--;
                    numsIndex++;
                    if (numsIndex >= nums.size()) return ret;
                }
            }
            i++;
        }

        return ret;
    }
    */
    bool isDistinct(const vector<int>& nums, int start) {
        unordered_set<int> seen;
        for (int i = start; i < nums.size(); i++) {
            if (seen.count(nums[i])) {
                return false;
            }
            seen.insert(nums[i]);
        }
        return true;
    }
    
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int maxOps = (n+2) / 3;
        
        int lo = 0, hi = maxOps, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int startIndex = mid * 3;
            if (startIndex >= n || isDistinct(nums, startIndex)) {
                ans = mid;
                hi = mid - 1;
            } 
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
