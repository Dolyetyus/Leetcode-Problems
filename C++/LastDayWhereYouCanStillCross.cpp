class Solution {
public:
    bool solve(vector<vector<int>> &dayM, int mid, int row, int col, vector<vector<int>> &vis){
        int n = dayM.size();
        int m = dayM[0].size();

        vis[row][col] = 1;
        
        if (row == n-1) return true;

        int rv[4] = {0, 1, 0, -1};
        int cv[4] = {-1, 0, 1, 0};

        for (int i = 0; i<=3; i++) {
            int nr = row+rv[i];
            int nc = col+cv[i];

            if (nr>=0 && nr<n && nc>=0 && nc< m && !vis[nr][nc] && dayM[nr][nc]>mid) {
                if (solve(dayM, mid, nr, nc, vis)) return true;
            }
        }
        return false;
    }

    bool isValidDay(vector<vector<int>> &dayM, int mid){
        int n = dayM.size();
        int m = dayM[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> pathVis(n, vector<int>(m, 0));

        for (int i = 0; i<m; i++) {
            if (dayM[0][i]>mid && solve(dayM, mid, 0, i,vis)) return true;
            vis = pathVis;
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int miniDay = INT_MAX;
        int n = cells.size();
        int day = 1;
        vector<vector<int>> dayM(row, vector<int>(col));
        
        for (int i = 0; i<n; i++){
            dayM[cells[i][0]-1][cells[i][1]-1] = day;
            day++;
        }

        int start = 1;
        int end = (row*col);
        while(start<=end){
            int mid = (start+end)/2;
            bool isDay = isValidDay(dayM, mid);

            if (isDay) {
                miniDay = mid;
                start=mid+1;
            }
            else end=mid-1;
        }

        return miniDay;
    }
};
