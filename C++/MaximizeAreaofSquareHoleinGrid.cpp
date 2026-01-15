class Solution {
public:
    int findLen(vector<int>& bars){
        sort(bars.begin(), bars.end());

        int bz = bars.size();
        int len = 1, maxLen = 1;

        for (int i=0; i<bz-1; i++){
            len = 1+(-(bars[i]+1 == bars[i+1]) & len);
            maxLen = max(len, maxLen);
        }

        return maxLen;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int len = 1 + min(findLen(hBars), findLen(vBars));

        return len*len;
    }
};
