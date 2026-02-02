 class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        multiset<long long> small, large;
        long long sumSmall = 0;
        int need = k-1;

        auto add = [&](long long x) {
            if ((int)small.size() < need) {
                small.insert(x);
                sumSmall += x;
            } 
            else {
                auto it = prev(small.end());
                if (*it > x) {
                    sumSmall -= *it;
                    large.insert(*it);
                    small.erase(it);
                    small.insert(x);
                    sumSmall += x;
                } 
                else large.insert(x);
            }
        };

        auto remove = [&](long long x) {
            auto it = small.find(x);
            if (it != small.end()) {
                sumSmall -= x;
                small.erase(it);
                if (!large.empty()) {
                    auto jt = large.begin();
                    sumSmall += *jt;
                    small.insert(*jt);
                    large.erase(jt);
                }
            } 
            else large.erase(large.find(x));
        };

        for (int i = 1; i<=dist+1; i++) add(nums[i]);

        long long ret = sumSmall;
        for (int i = dist+2; i<n; i++) {
            add(nums[i]);
            remove(nums[i-(dist+1)]);
            ret = min(ret, sumSmall);
        }

        return ret+nums[0];
    }
};
