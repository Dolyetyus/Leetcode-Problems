class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if (k > total) return "";

        string res;
        for (int i = 0; i < n; ++i) {
            vector<char> possible;
            if (res.empty()) {
                possible = {'a', 'b', 'c'};
            } 
            else {
                char last = res.back();
                for (char c : {'a', 'b', 'c'}) {
                    if (c != last) possible.push_back(c);
                }
            }
            for (char c : possible) {
                int remaining = n - res.size() - 1;
                int cnt = 1 << remaining;
                if (k <= cnt) {
                    res.push_back(c);
                    break;
                } 
                else {
                    k -= cnt;
                }
            }
        }
        return res;
    }
};
