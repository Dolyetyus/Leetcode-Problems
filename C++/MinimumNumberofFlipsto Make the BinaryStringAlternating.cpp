class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string str = s+s;
        int startWithOne = 0;
        int startWithZero = 0;
        int ret = INT_MAX;
        int i = 0;

        for (int j = 0; j<str.length(); j++) {
            bool flag = (j % 2 == 0);

            if (flag) {
                if (str[j] != '1') startWithOne++;
                if (str[j] != '0') startWithZero++;
            }
            else {
                if (str[j] != '0') startWithOne++;
                if (str[j] != '1') startWithZero++;
            }

            if (j-i+1 > n) {
                bool prevFlag = (i % 2 == 0);

                if (prevFlag) {
                    if (str[i] != '1') startWithOne--;
                    if (str[i] != '0') startWithZero--;
                }
                else {
                    if (str[i] != '0') startWithOne--;
                    if (str[i] != '1') startWithZero--;
                }
                i++;
            }

            if (j-i+1 == n) ret = min(ret, min(startWithOne, startWithZero));
        }

        return ret;
    }
};
