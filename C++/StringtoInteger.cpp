class Solution {
public:
    /*int myAtoi(string s) {
        int ret = 0;
        bool negative = false;
        for (char digit: s){
            if (digit<58 && digit>47){
                ret *= 10;
                int num = digit - '0';
                ret += num;
            }
            else if (digit == '-') negative=true;
        }

        return (negative) ? -1*ret : ret;
    }*/

    int myAtoi(string s) {
        int i = 0;
        while (s[i] == ' ') { ++i; } 

        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') sign = -1;
            ++i;
        }

        long long ret = 0;
        while (s[i] >= '0' && s[i] <= '9') {
            ret = ret * 10 + (s[i] - '0');
            if (sign == 1 && ret > INT_MAX) return INT_MAX;
            if (sign == -1 && ret > (long long)INT_MAX + 1) return INT_MIN;
            ++i;
        }

        return sign * ret;
    }
};
