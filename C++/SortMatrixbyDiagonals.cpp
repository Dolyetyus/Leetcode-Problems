class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int x = 0;
        int y = 0;

        for (int i = 0; i<grid.size(); i++) {
            priority_queue<int> pq;
            x = i;
            y = 0;

            while (x<grid.size()) {
                pq.push(grid.at(x).at(y));
                x++;
                y++;
            }

            x = i;
            y = 0;
            while (x<grid.size()) {
                grid.at(x).at(y) = pq.top();
                pq.pop();
                x++;
                y++;
            }
        }

        for (int i = 1; i<grid.at(0).size(); i++) {
            priority_queue<int, vector<int>, greater<int> > pq;
            x = 0;
            y = i;

            while (y<grid.at(0).size()) {
                pq.push(grid.at(x).at(y));
                x++;
                y++;
            }

            x = 0;
            y = i;
            while (y<grid.at(0).size()) {
                grid.at(x).at(y) = pq.top();
                pq.pop();
                x++;
                y++;
            }
        }

        return grid;
    }
};
