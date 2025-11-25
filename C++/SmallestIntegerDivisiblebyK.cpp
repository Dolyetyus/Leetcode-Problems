class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k%2 == 0 || k%5 == 0) return -1;
        unordered_set<int> remainders;
        int n = 1;
        int ret = 1;

        while (n%k != 0) {
            if (remainders.count(n)) return -1;
            remainders.insert(n);
            n *= 10;
            n++;
            n %= k;
            ret++;
        }

        return ret;
    }
};
