class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int ret = 0;
        
        long long newMin = 0;
        long long newMax = 0;
        long long curr = 0;
        for (int num: differences){
            curr += num;
            if (curr>newMax) newMax = curr;
            if (curr<newMin) newMin = curr;
        }

        long long min = lower-newMin;
        long long max = upper-newMax;

        if (max<min) return 0;
        return max-min+1;
    }
};
