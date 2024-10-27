class Solution {
public:
    int count(vector<vector<int>>& matrix, int squareSize){
        int ret = 0;
        int n = matrix.size();
        int m = matrix.at(0).size();

        for (int y = 0; y <= n-squareSize; y++) {
            for (int x = 0; x <= m-squareSize; x++) {
                bool isValid = true;
                for (int i = 0; i<squareSize; i++) {
                    for (int j = 0; j<squareSize; j++) {
                        if (matrix.at(y+i).at(x+j) != 1) {
                            isValid = false;
                            break;
                        }
                    }
                    if (!isValid) break;
                }
                if (isValid) ret++;
            }
        }
        return ret;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int ret = 0;
        int maxSide = matrix.size();
        if (matrix.at(0).size() < maxSide){
            maxSide = matrix.at(0).size();
        }

        for (int i = 1; i<=maxSide; i++){
            ret += count(matrix, i);
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
