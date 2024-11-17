class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<long long> prefixSum(n+1, 0);
        int shortest = INT_MAX;

        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }

        for (int i = 0; i <= n; ++i) {
            while (!dq.empty() && prefixSum[i]-prefixSum[dq.front()] >= k) {
                shortest = min(shortest, i-dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return (shortest == INT_MAX) ? -1 : shortest;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
