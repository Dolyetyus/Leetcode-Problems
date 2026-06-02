class Solution {
public:
    int calFinishTime(vector<int>& ls,vector<int>& ld,vector<int>& ws,vector<int>& wd) {
        int mini = INT_MAX;

        for (int i = 0; i<ls.size(); i++) {
            mini = min(mini, ls[i]+ld[i]);
        }

        int ret = INT_MAX;
        for (int i = 0; i<ws.size(); i++) {
            ret = min(ret, max(mini, ws[i]) + wd[i]);
        }

        return ret;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(calFinishTime(landStartTime,landDuration,waterStartTime,waterDuration), calFinishTime(waterStartTime,waterDuration,landStartTime,landDuration));
    }
};
