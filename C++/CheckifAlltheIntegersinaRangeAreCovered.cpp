class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (; left<=right; left++){
            bool covered = false;
            for (int i = 0; i<ranges.size(); i++){
                if (ranges.at(i).at(0)<=left && ranges.at(i).at(1)>=left) {
                    covered = true;
                    break;
                }
            }
            if (!covered) return false;
        }

        return true;
    }
};
