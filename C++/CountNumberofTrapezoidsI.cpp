class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1000000007;
        unordered_map <int, int> C;

        for (auto p: points){
            C[p[1]] += 1;
        }

        long long sum = 0;
        long long ret = 0;
        for (auto [y, Cy] : C){
            long long Vy = (long long)Cy * (Cy - 1) / 2;
            ret += sum * Vy;
            ret %= mod;
            sum += Vy;
            sum %= mod;
        }

        return ret;
    }
};
