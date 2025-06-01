#define ll long long
class Solution {
public:
    long long distributeCandies(int n, int l) {
        ll ret = 0;

        for (ll x = max(0ll, (ll)n - 2 * (ll)l); x <= min((ll)n, (ll)l); x++) {
            ll y_st = max(0ll, (ll)n - (ll)l - x);
            ll y_en = min((ll)n - x, (ll)l);

            if (y_st <= y_en) {
                ll range = (y_en - y_st + 1);
                ret += range;
            }
        }

        return ret;
    }
};
