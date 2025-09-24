class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int, int> remainderIndex;
        string res = "";

        long long num = numerator;
        long long den = denominator;

        if ((num < 0) ^ (den < 0)) res.push_back('-');
        num = llabs(num);
        den = llabs(den);

        res.append(to_string(num / den));
        long long remainder = num % den;
        if (remainder == 0) {
            if (res=="-0") return "0";
            return res;
        }

        res.push_back('.');

        while (remainder) {
            if (remainderIndex.count(remainder)) {
                res.insert(remainderIndex[remainder], "(");
                res.push_back(')');
                break;
            }

            remainderIndex[remainder] = res.size();

            remainder *= 10;
            res.push_back('0' + remainder / den);
            remainder %= den;
        }

        return res;
    }

    /* TLE lol
    string fractionToDecimal(int numerator, int denominator) {
        unordered_set<int> remainders;
        string res = "";
        string occ = "(";
        long long num = numerator;
        long long den = denominator;
        int remainder = 0;
        int tracking = -1;

        res.append(to_string(num/den));
        remainder = num%den;
        num /= den;
        remainders.insert(remainder);

        if (remainder==0) return res;
        else if (remainder<0) remainder *= -1;
        res.push_back('.');

        while (num<den) {
            if (remainder==0) break;
            num = remainder*10;
            remainder = num%den;

            if (tracking!=-1) occ.append(to_string(num/den));
            else res.append(to_string(num/den));

            num /= den;
            if (tracking==remainder) {
                occ.push_back(')');
                int size = occ.size()-2;
                res.insert(res.size()-size, occ);
                res.erase(res.length()-size);
                break;
            }
            if (remainders.find(remainder) != remainders.end()) tracking = remainder;
        }

        return res;
    }
    */
};
