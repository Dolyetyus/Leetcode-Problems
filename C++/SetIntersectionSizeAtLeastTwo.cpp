class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        vector<int> nums; 
        int a = -1, b = -1;
        for (vector<int> in : intervals) {
            int start = in[0];
            int end = in[1];

            bool hasA = (a >= start && a <= end);
            bool hasB = (b >= start && b <= end);

            if (hasA && hasB) continue;
            else if (hasB) {
                int x = end;
                nums.push_back(x);
                a = b;
                b = x;
            }
            else if (hasA) {                  
                nums.push_back(end-1);
                nums.push_back(end);
                b = end;
                a = end - 1;
            }
            else {
                nums.push_back(end-1);
                nums.push_back(end);
                a = end - 1;
                b = end;
            }
        }

        return nums.size();
    }
};
