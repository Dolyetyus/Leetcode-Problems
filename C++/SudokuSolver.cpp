class Solution {
public:
    struct State {
        int row, col;
        int num;
    };

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == c) return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> empties;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') empties.push_back({i, j});
            }
        }

        stack<State> st;
        int i = 0;

        while (i < empties.size()) {
            int row = empties[i].first;
            int col = empties[i].second;
            char start = '1';
            if (!st.empty() && st.top().row == row && st.top().col == col) {
                start = st.top().num + 1;
                board[row][col] = '.';
                st.pop();
            }

            bool placed = false;
            for (char c = start; c <= '9'; c++) {
                if (isValid(board, row, col, c)) {
                    board[row][col] = c;
                    st.push({row, col, c});
                    placed = true;
                    break;
                }
            }

            if (placed) i++; 
            else i--; 
        }
    }
};
