class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ret(m, vector<int>(n, -1));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir_id = 0;
        int x = 0, y = 0;
        std::unordered_set<int> visited;

        while (head != NULL) {
            ret[y][x] = head->val;
            visited.insert(y * n + x);
            head = head->next;

            int next_x = x + directions[dir_id][1];
            int next_y = y + directions[dir_id][0];

            if (next_x >= n || next_x < 0 || next_y >= m || next_y < 0 || 
            visited.count(next_y * n + next_x)) {
                dir_id = (dir_id + 1) % 4;
                next_x = x + directions[dir_id][1];
                next_y = y + directions[dir_id][0];
            }

            x = next_x;
            y = next_y;
        }

        return ret;
    }
};
