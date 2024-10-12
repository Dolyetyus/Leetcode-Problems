class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> endTimes;

        for (const auto& interval : intervals) {
            if (!endTimes.empty() && endTimes.top() < interval[0]) {
                endTimes.pop();
            }

            endTimes.push(interval[1]);
        }

        return endTimes.size();
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
