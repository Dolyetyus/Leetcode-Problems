class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int,int>> row;
        unordered_map<int, pair<int,int>> col;
        int ret = 0;

        for (vector<int> b: buildings) {
            int x = b[0];
            int y = b[1];

            if (!row.count(y)) row[y] = {x, x};
            else {
                row[y].first = min(row[y].first, x);
                row[y].second = max(row[y].second, x);
            }

            if (!col.count(x)) col[x] = {y, y};
            else {
                col[x].first = min(col[x].first, y);
                col[x].second = max(col[x].second, y);
            }
        }

        for (vector<int> b : buildings) {
            int x = b[0];
            int y = b[1];
            auto& r = row[y];
            auto& c = col[x];

            if (x > r.first && x < r.second && y > c.first && y < c.second) ret++;
        }

        return ret;
    }
};
