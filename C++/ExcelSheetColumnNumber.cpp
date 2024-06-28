class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ret = 0;

        for (int i = 0; i < columnTitle.size(); i++){
            ret = ret * 26 + (columnTitle[i] - 'A' + 1);
        }

        return ret;
    }
};
