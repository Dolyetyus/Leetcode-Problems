class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows==1 || n < numRows) return s;
        int id = n;
        int cols = 0;

        while (id>0) {
            id -= numRows;
            cols++;
            id -= numRows-2;
            cols+=numRows-2;
        }

        vector<vector<char>> mat(numRows, vector<char>(cols, '-'));
        bool up = false;
        int x = 0;
        int y = 0;

        id = n;
        while (id>0){
            if (!up) {
                mat.at(x).at(y) = s.at(n-id);
                if (x==numRows-1) { 
                    up = !up;
                    x--;
                    y++;
                }
                else x++;
            }
            else {
                mat.at(x).at(y) = s.at(n-id);
                if (x==0) { 
                    up = !up;
                    x++;
                }
                else {
                    x--;
                    y++;
                }
            }
            id--;
        }

        string ret;
        for (int i = 0; i<numRows; i++) {
            for (int ii = 0; ii<cols; ii++) {
                if (mat.at(i).at(ii) != '-') ret.push_back(mat.at(i).at(ii));
            }
        }

        return ret;
    }
};
