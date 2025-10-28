class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()<2) return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ret;
        vector<int> ids(intervals.size());

        int id = 0;
        ids[0] = id;
        int currLargest = intervals[0][1];
        for (int i = 1; i<intervals.size(); i++) {
            if (currLargest>=intervals[i][0]) ids[i] = ids[i-1];
            else {
                id++;
                ids[i] = id;
            }
            currLargest = max(currLargest, intervals[i][1]);
        }

        int left = 0;
        int largest = 0;
        for (int right = 0; right<ids.size();) {
            left = right;
            largest = intervals[left][1];
            while (right<ids.size() && ids[right] == ids[left]) {
                largest = max(largest, intervals[right][1]);
                right++;
            }
            ret.push_back({intervals[left][0], largest});
        }

        return ret;
    }
};
