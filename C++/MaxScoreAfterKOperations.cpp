class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> queue;
        long long ret = 0;

        for (int i = 0; i < nums.size(); i++) {
            queue.push(nums[i]);
        }

        for (int i = 0; i < k; i++) {
            int val = queue.top();
            queue.pop();
            ret += val;
            val = static_cast<int>(ceil(val/3.0));
            queue.push(val);
        }

        return ret;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
