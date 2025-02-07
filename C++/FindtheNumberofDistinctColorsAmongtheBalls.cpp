class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int distinct = 0;
        unordered_map<int, int> colours;
        unordered_map<int, int> balls;
        vector<int> ret(queries.size());
        int i = 0;

        for (vector<int> query: queries){
            int ball_colour = balls[query.at(0)];
            int new_colour = query.at(1);
            if (ball_colour != new_colour){
                int num_ball_col = colours[ball_colour];
                if (num_ball_col>0) {
                    colours[ball_colour]--;
                    if (num_ball_col == 1) distinct--;
                }

                balls[query.at(0)] = new_colour;
                if (colours[new_colour]==0) distinct++;
                colours[new_colour]++;
            }

            ret[i] = distinct;
            i++;
        }

        return ret;
    }
};
