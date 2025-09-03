class Solution {
public:
    int numberOfPairs(std::vector<std::vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int n = points.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = numeric_limits<int>::min();

            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (y2 <= y1) {
                    if (y2 > maxY) {
                        count++;
                        maxY = y2;
                    }
                }
            }
        }
        return count;
    }
};
