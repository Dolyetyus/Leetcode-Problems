class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int n = nums.size();
        constexpr int mod = 1000000007;
        multiset<int> win;
        long long ret = 0;
        int* sum = (int*)alloca((n+2) * sizeof(int));

        memset(sum, 0, sizeof(sum));
        sum[1] = 1;
        for (int l = 0, r = 0; r<n; r++) {
            const int x=nums[r];
            win.insert(x);
            while (*(prev(win.end()))-*win.begin()>k) {
                auto it = win.lower_bound(nums[l++]);
                win.erase(it);
            }
            ret = (mod+sum[r+1]-sum[l]) % mod;
            sum[r+2] = (sum[r+1]+ret) % mod;
            
        }
        
        return ret;
    }
};
