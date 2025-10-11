class Solution {
public:
    int n;
    unordered_map<int,int> freq;
    vector<long long> dp;

    long long solve(int idx, vector<int>& power) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];

        long long notChoose = solve(idx + 1, power);
        int j = idx + 1;
        while (j < n && power[j] < power[idx] + 3) j++;
        long long choose = 1LL * power[idx] * freq[power[idx]] + solve(j, power);

        return dp[idx] = max(choose, notChoose);
    }

    long long maximumTotalDamage(vector<int>& power) {
        for (int p : power) freq[p]++;
        vector<int> vals;
        for (auto &p : freq) vals.push_back(p.first);
        sort(vals.begin(), vals.end());

        n = vals.size();
        dp.assign(n + 1, -1);

        return solve(0, vals);
    }
};
