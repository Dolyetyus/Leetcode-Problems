class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;

        for (auto& s: squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)(s[1] + s[2]));
        }

        auto areaDiff = [&](double h) {
            double above = 0.0, below = 0.0;

            for (auto& s: squares) {
                double y = s[1];
                double l = s[2];
                double bottom = y;
                double top = y + l;

                if (top <= h) below += l*l;
                else if (bottom >= h) above += l*l;
                else {
                    below += l * (h - bottom);
                    above += l * (top - h);
                }
            }

            return above-below;
        };

        for (int i = 0; i<80; i++) {
            double mid = (low+high) / 2.0;
            if (areaDiff(mid) > 0) low = mid;
            else high = mid;
        }

        return (low+high) / 2.0;
    }
};
