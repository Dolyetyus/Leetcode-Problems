class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b){ return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> avail;

        for (int i = 0; i < n; ++i) avail.push(i);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;
        vector<int> cnt(n);

        for (auto &m : meetings) {
            long long s = m[0], e = m[1];
            while (!busy.empty() && busy.top().first <= s) {
                avail.push(busy.top().second);
                busy.pop();
            }

            long long start;
            int r, dur = e - s;

            if (!avail.empty()) {
                r = avail.top(); avail.pop();
                start = s;
            } 
            else {
                auto p = busy.top(); busy.pop();
                start = p.first; r = p.second;
            }

            busy.emplace(start + dur, r);
            ++cnt[r];
        }

        int best = 0;
        for (int i = 1; i < n; ++i) if (cnt[i] > cnt[best]) best = i;
        
        return best;
    }
};
