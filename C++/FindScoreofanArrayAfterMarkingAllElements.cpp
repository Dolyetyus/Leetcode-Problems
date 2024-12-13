class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        vector<bool> visited(n, false);

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) 
            return a.second > b.second; 
            return a.first > b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        while (!pq.empty()) {
            auto [value, index] = pq.top();
            pq.pop();

            if (visited[index]) continue;

            score += value;
            visited[index] = true;

            if (index - 1 >= 0) visited[index-1] = true;
            if (index + 1 < n) visited[index+1] = true;
        }

        return score;
    }
};
