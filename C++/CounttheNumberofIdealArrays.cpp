class Solution {
public:
    int idealArrays(int n, int maxValue) {
        static int comb[10001][14] = {1};
        static int cnt[10001][14] = {};
        int mod = 1000000007;

        if (comb[1][1] == 0) {
            for (int s = 1; s <= 10000; ++s) {
                for (int r = 0; r < 14; ++r) {
                    comb[s][r] = r == 0 ? 1 : (comb[s - 1][r - 1] + comb[s - 1][r]) % mod;
                }
            }

            for (int div = 1; div <= 10000; ++div) {
                ++cnt[div][0];
                for (int i = 2 * div; i <= 10000; i += div) {
                    for (int bars = 0; cnt[div][bars]; ++bars) {
                        cnt[i][bars + 1] += cnt[div][bars];
                    }
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= maxValue; ++i) {
            for (int bars = 0; bars < min(14, n) && cnt[i][bars]; ++bars) {
                res = (1LL * cnt[i][bars] * comb[n - 1][bars] + res) % mod;
            }
        }

        return res;
    }
    /*
    int idealArrays(int n, int maxValue) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(maxValue + 1, 1);
        for (int i = 2; i <= n; ++i) {
            vector<long long> new_dp(maxValue + 1, 0);
            for (int v = 1; v <= maxValue; ++v) {
                for (int d = 1; d * d <= v; ++d) {
                    if (v % d == 0) {
                        new_dp[v] = (new_dp[v] + dp[d]) % MOD;
                        if (d != v / d) {
                            new_dp[v] = (new_dp[v] + dp[v / d]) % MOD;
                        }
                    }
                }
            }
            dp = move(new_dp);
        }
        long long total = 0;
        for (int v = 1; v <= maxValue; ++v) {
            total = (total + dp[v]) % MOD;
        }
        return total;
    }
    */
};
