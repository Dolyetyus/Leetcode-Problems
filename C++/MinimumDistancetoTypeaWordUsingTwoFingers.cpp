class Solution {
public:
    int dist(int a, int b){
        if (a==26 || b==26) return 0;
        return abs(a/6-b/6) + abs(a%6-b%6);
    }

    int minimumDistance(string word) {
        int n = word.size();
        const int INF = 1e9;

        vector<int> dp(27, INF);
        dp[26] = 0;

        for (int i = 1;i<n;i++) {
            vector<int> next(27, INF);

            int prev = word[i-1]-'A';
            int cur  = word[i]-'A';

            for (int j = 0;j<=26;j++) {
                if(dp[j] == INF) continue;

                next[j] = min(next[j], dp[j] + dist(prev,cur));
                next[prev] = min(next[prev], dp[j] + dist(j,cur));
            }

            dp = next;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
