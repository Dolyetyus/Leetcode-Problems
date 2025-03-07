class Solution {
public:
    vector<int> sieve(int n, int left, int right) {
        vector<bool> prime(n + 1, true);
        vector<int> ret;

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        
        if (left<2) left = 2;
        for (int p = left; p <= right; p++)
            if (prime[p]) ret.push_back(p);

        return ret;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> arr = sieve(right, left, right);
        vector<int> ret(2);
        int min_diff = 9999999;

        for (int i = arr.size()-1; i>=1; i--){
            if (arr.at(i)-arr.at(i-1) <= min_diff) {
                min_diff = arr.at(i)-arr.at(i-1);
                ret.at(0) = arr.at(i-1);
                ret.at(1) = arr.at(i);
            }
        }

        if (min_diff==9999999) return {-1, -1};
        return ret;
    }
};
