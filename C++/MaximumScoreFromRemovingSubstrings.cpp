class Solution {
public:
    int removeSubstr(string& s, char first, char second, int score) {
        stack<char> st;
        int points = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == first && c == second) {
                st.pop();
                points += score;
            } 
            else st.push(c);
        }

        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        s = remaining;

        return points;
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;

        if (x > y) {
            total += removeSubstr(s, 'a', 'b', x);
            total += removeSubstr(s, 'b', 'a', y);
        } 
        else {
            total += removeSubstr(s, 'b', 'a', y);
            total += removeSubstr(s, 'a', 'b', x);
        }

        return total;
    }
};
