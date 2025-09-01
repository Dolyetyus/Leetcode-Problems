class Solution {
public:
    struct item {
        int pass;
        int total;
        double gain() const {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        }
    };

    struct Compare {
        bool operator()(const item& a, const item& b) {
            return a.gain() < b.gain();
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<item, vector<item>, Compare> pq;

        for (auto& cla: classes) pq.push({cla[0], cla[1]});

        while (extraStudents-- > 0) {
            auto curr = pq.top(); pq.pop();
            curr.pass++;
            curr.total++;
            pq.push(curr);
        }

        double tot = 0.0;
        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            tot += (double)curr.pass / curr.total;
        }

        return tot / classes.size();
    }
};
