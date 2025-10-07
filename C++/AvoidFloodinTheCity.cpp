class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ret(n, 1); 
        unordered_map<int, int> lastRain;
        set<int> dryDays;
        set<int> fullLakes;

        for (int i = 0; i < n; ++i) {
            int lake = rains.at(i);
            if (lake == 0) {
                dryDays.insert(i);
            } 
            else {
                if (fullLakes.count(lake)) {
                    int last = lastRain[lake];
                    auto it = dryDays.lower_bound(last);
                    if (it == dryDays.end()) return {};
                    int dryDay = *it;
                    ret[dryDay] = lake;
                    dryDays.erase(it);
                    fullLakes.erase(lake);
                }
                fullLakes.insert(lake);
                lastRain[lake] = i;
                ret.at(i) = -1;
            }
        }

        return ret;
    }
    
    /*
    vector<int> avoidFlood(vector<int>& rains) {
        queue<int> dryDays;
        set<int> fullLakes;
        vector<int> ret(rains.size());

        for (int i = 0; i<rains.size(); i++) {
            if (rains.at(i) == 0) {
                dryDays.push(i);
                ret.at(i) = 1;
            }
            else {
                if (fullLakes.contains(rains.at(i))) {
                    if (dryDays.empty()) return {};
                    else {
                        int day = dryDays.front();
                        dryDays.pop();
                        ret.at(day) = rains.at(i);
                        fullLakes.erase(rains.at(i));
                    }
                }
                fullLakes.insert(rains.at(i));
                ret.at(i) = -1;
            }
        }

        return ret;
    }
    */
};
