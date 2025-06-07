class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<stack<int>> freq(26);

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; j++) {
                    if (!freq[j].empty()) {
                        s[freq[j].top()] = '*';
                        freq[j].pop();
                        break;
                    }
                }
            }
            else freq[s[i] - 'a'].push(i); 
        }

        string result = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') result += s[i];
        }

        return result;
    }
};
