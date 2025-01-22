class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<tuple<int, int, int>> cells;
        vector<vector<int>> ret = isWater;

        for (int i = 0; i<isWater.size(); i++){
            for (int ii = 0; ii<isWater.at(0).size(); ii++){
                ret[i][ii] = -1;
                if (isWater[i][ii]==1) {
                    cells.push({i, ii, 0});
                    ret[i][ii] = 0;
                }
            }
        }

        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!cells.empty()) {
            auto [y, x, val] = cells.front();
            cells.pop();
            
            for (auto dir: dirs){
                if (y+dir[0]>=0 && y+dir[0]<isWater.size() && x+dir[1]>=0 && x+dir[1]<isWater[0].size() && ret[y+dir[0]][x+dir[1]] == -1){
                    ret[y+dir[0]][x+dir[1]] = val+1;
                    cells.push({y+dir[0], x+dir[1], val+1});
                }
            }
        }

        return ret;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
