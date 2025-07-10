class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gap(n + 1);
        int lastEnd = 0;
        
        for (int i = 0; i < n; i++){
            gap[i] = startTime[i] - lastEnd;
            lastEnd = endTime[i];
        }

        gap[n] = eventTime - lastEnd;
        vector<int> rightMax(n+1, 0);

        for (int i = n - 1; i >= 0; i--){
            rightMax[i] = max(rightMax[i + 1], gap[i + 1]);
        }

        int leftMax = 0;
        int maxGap = 0;

        for (int i = 1; i <= n; i++){
            int dur = endTime[i - 1] - startTime[i - 1];
            int gapL = gap[i - 1];
            int gapR = gap[i];

            if (leftMax >= dur || rightMax[i] >= dur){
                maxGap = max(maxGap, gapL + dur + gapR);
            }

            maxGap = max(maxGap, gapL + gapR);
            leftMax = max(leftMax, gapL);
        }

        return maxGap;
    }
};
