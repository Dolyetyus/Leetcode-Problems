class Solution {
public:
    static string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, 'a'-1);
        int id = -1;

        for (int i=0; i<n; i++) {
            if (s[i]>='a') continue;
            if (++id>=26) return "";

            for (int j = 0; j<n; j++)
                if (lcp[i][j]) s[j] = 'a'+id;
        }

        for (int i = 0; i<n; i++) {
            if (lcp[i][i] != n-i) return "";

            for (int j = 0; j<i; j++) {
                const int x = lcp[i][j];

                if (x!=lcp[j][i]) return "";

                int y = 0;
                if (s[i] == s[j]) {
                    if (i+1 < n && j+1 < n)  y = 1 + lcp[i+1][j+1];
                    else y = 1;
                } 
                else y = 0;

                if (x != y) return "";
            }
        }

        return s;
    }
};
