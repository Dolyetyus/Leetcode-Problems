class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minSuffix(n);
        minSuffix[n-1] = s[n-1];

        for (int i = n-2; i >= 0; --i) {
            minSuffix[i] = min(s[i], minSuffix[i+1]);
        }

        stack<char> stk;
        string result;
        int i = 0;

        while (i < n) {
            stk.push(s[i]); 
            i++;

            while (!stk.empty() && (i == n || stk.top() <= minSuffix[i])) {
                result += stk.top();
                stk.pop();
            }
        }

        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        return result;
    }
};
