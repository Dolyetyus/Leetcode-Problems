class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size()%2==1) return false;

        int n = s.size();
        int openCount = 0;
        int freeCount = 0;

        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') openCount++;
                else openCount--;
            } 
            else {
                freeCount++;
            }

            if (openCount + freeCount < 0) return false;
        }

        openCount = 0;
        freeCount = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '1') {
                if (s[i] == ')') openCount++;
                else openCount--;
            } 
            else {
                freeCount++;
            }

            if (openCount + freeCount < 0) return false;
        }

        return true;
    }
};
