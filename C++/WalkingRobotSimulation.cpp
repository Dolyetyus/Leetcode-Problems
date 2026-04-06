class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obstacle_set;
        for (const auto& obs: obstacles) {
            long long key = ((long long)obs[0] << 32) | (unsigned int)obs[1];
            obstacle_set.insert(key);
        }

        int x = 0, y = 0;
        int direction = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ret = 0;

        for (int command: commands) {
            if (command == -1) direction = (direction+1) % 4;
            else if (command == -2) direction = (direction+3) % 4;
            else {
                for (int i = 0; i<command; i++) {
                    int nextX = x + directions[direction].first;
                    int nextY = y + directions[direction].second;

                    long long key = ((long long)nextX << 32) | (unsigned int)nextY;

                    if (obstacle_set.find(key) == obstacle_set.end()) {
                        x = nextX;
                        y = nextY;
                        ret = max(ret, x*x + y*y);
                    } 
                    else break;
                }
            }
        }

        return ret;
    }
};
