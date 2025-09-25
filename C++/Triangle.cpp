class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = n-2; i>=0; i--){
            for (int ii = 0; ii<=i; ii++){
                triangle.at(i).at(ii) += min(triangle.at(i+1).at(ii), triangle.at(i+1).at(ii+1));
            }
        }

        return triangle.at(0).at(0);
    }
};
