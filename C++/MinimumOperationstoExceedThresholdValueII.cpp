class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long> > q(nums.begin(), nums.end());
        int ret = 0;

        if (q.top()>=k) return 0;

        while (true){
            long x = q.top();
            q.pop();
            long y = q.top();
            q.pop();

            q.push(min(x, y) * 2 + max(x, y));
            ret++;

            if (q.top()>=k) break;
        }

        return ret;
    }
};
