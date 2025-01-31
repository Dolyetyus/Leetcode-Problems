class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> groups(n, vector<int>(n, 0));
        unordered_map<int, int> groupSize;
        int currentGroup = 2;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && groups[i][j] == 0) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    groups[i][j] = currentGroup;
                    int size = 0;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        size++;
                        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                        for (auto& dir : dirs) {
                            int nx = x + dir.first;
                            int ny = y + dir.second;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1 && groups[nx][ny] == 0) {
                                groups[nx][ny] = currentGroup;
                                q.push({nx, ny});
                            }
                        }
                    }
                    groupSize[currentGroup] = size;
                    currentGroup++;
                }
            }
        }

        int initialMax = 0;
        for (auto& [k, v] : groupSize) {
            initialMax = max(initialMax, v);
        }

        int maxCandidate = 0;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighborGroups;
                    for (auto& dir : dirs) {
                        int ni = i + dir.first;
                        int nj = j + dir.second;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            neighborGroups.insert(groups[ni][nj]);
                        }
                    }
                    int sum = 1;
                    for (int g : neighborGroups) {
                        sum += groupSize[g];
                    }
                    maxCandidate = max(maxCandidate, sum);
                }
            }
        }

        return max(initialMax, maxCandidate);
    }
};
