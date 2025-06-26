class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        long long value = 0;
        int bit_limit = log2(k)+1;
        int bits_used = 0;

        for (int i = n-1; i >= 0; --i) {
            if (s[i] == '0') {
                count++;
                if (bits_used < bit_limit) bits_used++;
            } 
            else {
                if (bits_used < bit_limit) {
                    long long add = 1LL << bits_used;
                    if (value + add <= k) {
                        value += add;
                        count++;
                        bits_used++;
                    }
                }
            }
        }

        return count;
    }
};
