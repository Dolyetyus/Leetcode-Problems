class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ret;
        unordered_map<int, int> freq;

        for (int i = 0; i < k && i < nums.size(); i++) freq[nums[i]]++;

        auto calc = [&](unordered_map<int,int>& freq) {
            priority_queue<pair<int,int>> pq;
            for (auto& [num, f]: freq) pq.push({f, num});
            int total = 0;
            for (int i = 0; i < x && !pq.empty(); i++) {
                total += pq.top().first * pq.top().second;
                pq.pop();
            }
            return total;
        };

        ret.push_back(calc(freq));

        for (int i = k; i < nums.size(); i++) {
            if (--freq[nums[i - k]] == 0) freq.erase(nums[i - k]);
            freq[nums[i]]++;
            ret.push_back(calc(freq));
        }

        return ret;
    }

};
