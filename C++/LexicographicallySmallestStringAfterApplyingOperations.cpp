class Solution {
public:
    int gcd_int(int a, int b) { return b == 0 ? a : gcd_int(b, a%b); }

    void rotate(string& s, int times) {
        string dup = s;
        for (int i = 0; i<s.size(); i++) dup.at(i) = s.at((i-times+s.size())%s.size());
        s = dup;
    }

    void add(string& s, int n, int start) {
        for (int i = start; i<s.size(); i+=2) s.at(i) = char(((s.at(i)-'0'+n)%10) + '0');
    }

    string findLexSmallestString(string s, int a, int b) {
        string ret = s;
        string rotated = s;
        int cycleLen = s.size() / gcd_int(s.size(), b);

        for (int r = 0; r<cycleLen; r++) {
            for (int oddAdds = 0; oddAdds<10; oddAdds++) {
                string t = rotated;
                add(t, (oddAdds*a)%10, 1);

                if (b%2 == 1) {
                    for (int evenAdds = 0; evenAdds<10; evenAdds++) {
                        string u = t;
                        add(u, (evenAdds*a)%10, 0);
                        if (u < ret) ret = u;
                    }
                } 
                else if (t < ret) ret = t;
            }

            rotate(rotated, b);
        }

        return ret;
    }
};
