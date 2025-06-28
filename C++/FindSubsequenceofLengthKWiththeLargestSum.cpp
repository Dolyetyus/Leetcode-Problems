class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < nums.size(); i++) {
            maxHeap.push({nums.at(i), i});
        }

        vector<pair<int, int>> topK;
        for (int i = 0; i < k && !maxHeap.empty(); i++) {
            topK.push_back(maxHeap.top());
            maxHeap.pop();
        }

        sort(topK.begin(), topK.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        vector<int> ret;
        for (auto p: topK) {
            ret.push_back(p.first);
        }

        return ret;
    }
};
