class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ret;
        for (int hours = 0; hours<12; hours++) {
            for (int minutes = 0; minutes<60; minutes++) {
                if (__builtin_popcount(hours) + __builtin_popcount(minutes) == turnedOn) {
                    string time = to_string(hours);
                    time += ":";
                    if (minutes < 10) time += "0";
                    time += to_string(minutes);
                    ret.push_back(time);
                }
            }
        }
        return ret;
    }
};
