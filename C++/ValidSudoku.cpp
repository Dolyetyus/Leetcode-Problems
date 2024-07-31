class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (checkRow(board)&&checkColumn(board)&&checkBox(board))
            return true;
        return false;
    }

    bool checkRow(vector<vector<char>>& board){
        for (int i = 0; i<9; i++){
            vector<int> check(9, 0);
            for (int ii = 0; ii<9; ii++){
                if (!isdigit(board.at(i).at(ii))) continue;
                int index = board.at(i).at(ii)-'1';
                if (check.at(index)!=0){
                    return false;
                }
                check.at(index) = 1;
            }
        }
        return true;
    }

    bool checkColumn(vector<vector<char>>& board){
        for (int i = 0; i<9; i++){
            vector<int> check(9, 0);
            for (int ii = 0; ii<9; ii++){
                if (!isdigit(board.at(ii).at(i))) continue;
                int index = board.at(ii).at(i)-'1';
                if (check.at(index)!=0){
                    return false;
                }
                check.at(index) = 1;
            }
        }
        return true;
    }

    bool checkBox(vector<vector<char>>& board){
        for (int x = 0; x<9; x+=3){
            for (int y = 0; y<9; y+=3){
                vector<int> check(9, 0);
                for (int i = x; i<x+3; i++){
                    for (int ii = y; ii<y+3; ii++){
                        if (!isdigit(board.at(i).at(ii))) continue;
                        int index = board.at(i).at(ii)-'1';
                        if (check.at(index)!=0){
                            return false;
                        }
                        check.at(index) = 1;
                    }
                }
            }
        }
        return true;
    }
};
