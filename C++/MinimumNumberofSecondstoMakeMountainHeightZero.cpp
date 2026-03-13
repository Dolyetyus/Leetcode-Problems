class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using T = tuple<long long, int, int>; 
        priority_queue<T, vector<T>, greater<T>> min_pq;
        
        long long max_time = 0;

        for (int i=0; i < workerTimes.size(); i++) {
            min_pq.push({(long long)workerTimes[i], i, 1});
        }

        while (mountainHeight>0) {
            auto [finish_time, idx, x] = min_pq.top();
            min_pq.pop();
            
            max_time = finish_time; 
        
            long long next_unit_time = (long long)workerTimes[idx]*(x+1);
            min_pq.push({finish_time+next_unit_time, idx, x+1});

            mountainHeight--;
        }

        return max_time;
    }

    /* Lol I misread the question
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;
        long long ret = 0;

        for (int i = 0; i<workerTimes.size(); i++) min_pq.push({workerTimes[i], i});

        while (mountainHeight>0) {
            pair<int, int> worker = min_pq.top();
            min_pq.pop();
            ret += worker.first;

            min_pq.push({worker.first+workerTimes[worker.second], worker.second});

            mountainHeight--;
        }

        return ret;
    }*/
};
