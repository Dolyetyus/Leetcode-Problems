class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        time[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!pq.empty()) {
            auto [t, x, y] = pq.top(); pq.pop();
            if (x == n - 1 && y == m - 1) return t;

            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                int nt = max(t + 1, moveTime[nx][ny]);
                if (nt < time[nx][ny]) {
                    time[nx][ny] = nt;
                    pq.emplace(nt, nx, ny);
                }
            }
        }

        return -1;
    }
};
