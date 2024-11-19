class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ret = 0;
        long long currentSum = 0;
        unordered_set<int> set;
        unordered_map<int, int> freqMap;

        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];
            set.insert(nums[right]);
            freqMap[nums[right]]++;

            if (right - left + 1 > k) {
                currentSum -= nums[left];
                freqMap[nums[left]]--;

                if (freqMap[nums[left]] == 0) set.erase(nums[left]);

                left++;
            }

            if (right-left+1 == k && set.size() == k)
                ret = max(ret, currentSum);
        }

        return ret;
    }

    /* Time limit exceeded lmao
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ret = 0;
        for (int i = 0; i<nums.size()-k+1; i++){
            long long sum = 0;
            bool is_valid = true;
            unordered_set<long long> set;

            for (int ii = 0; ii<k; ii++){
                if (set.find(nums.at(i+ii)) != set.end()){
                    is_valid = false;
                    break;
                }
                set.insert(nums.at(i+ii));
                sum+=nums.at(i+ii);
            }

            if (is_valid && sum>ret) ret=sum;
            set.clear();
        }

        return ret;
    }
    */
};
