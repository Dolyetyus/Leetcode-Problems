class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool right = true;
        vector<int> ret;
        pair<int,int> loc = {0,0};

        while (!(loc.first == mat.size() || loc.second == mat.at(0).size())) {
            int x = loc.first;
            int y = loc.second;
            ret.push_back(mat.at(x).at(y));

            if (right) {
                if (x == 0) {
                    // hit top border -> [0, 1], change dir
                    if (y == mat.at(0).size()-1) loc.first++;
                    else loc.second++;
                    right = !right;
                }
                else if (y == mat.at(0).size()-1) {
                    // hit right border -> [1, 0], channge dir
                    loc.first++;
                    right = !right;
                }
                else {
                    loc.first--;
                    loc.second++;
                }
            }
            else {
                if (y == 0) {
                    // hit left border -> [1, 0], change dir
                    if (x == mat.size()-1) loc.second++;
                    else loc.first++;
                    right = !right;
                }
                else if (x == mat.size()-1) {
                    // hit bottom border -> [0, 1], channge dir                    
                    loc.second++;
                    right = !right;
                }
                else {
                    loc.first++;
                    loc.second--;
                }
            }
        }

        return ret;
    }
};
