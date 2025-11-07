class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> prefix(n+1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefix[i+1] = prefix[i] + stations[i];
        }
        
        vector<long long> power(n, 0);
        for (int i = 0; i < n; ++i) {
            int left = max(0, i-r);
            int right = min(n-1, i+r);
            power[i] = prefix[right+1] - prefix[left];
        }
        
        long long low = 0, high = accumulate(stations.begin(), stations.end(), 0LL) + k, ret = 0;
        
        auto can = [&](long long x) {
            vector<long long> added(n, 0);
            long long used = 0, currAdd = 0;
            
            for (int i = 0; i < n; ++i) {
                if (i-r-1 >= 0) currAdd -= added[i-r-1];
                
                long long currPower = power[i] + currAdd;
                if (currPower < x) {
                    long long need = x - currPower;
                    if (need > k - used) return false;
                    used += need;
                    added[min(n-1, i+r)] += need;
                    currAdd += need;
                }
            }
            return used <= k;
        };
        
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(mid)) {
                ret = mid;
                low = mid + 1;
            } 
            else high = mid - 1;
        }
        
        return ret;
    }
};
