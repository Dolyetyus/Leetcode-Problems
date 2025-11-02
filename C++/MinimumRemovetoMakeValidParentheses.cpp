class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string ret;

        for (int i = 0; i<s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (!st.empty()) st.pop();
                else s[i] = '-';
            }
        }

        while (!st.empty()) {
            s[st.top()] = '-';
            st.pop();
        }

        for (char chr: s) {
            if (chr!='-') ret.push_back(chr);
        }

        return ret;
    }
};
