class Solution {
public:
/*
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>, vector<vector<double>>, greater<>> heap;

        for (vector<int> cls: classes){
            int total_size = cls.at(0)+cls.at(1);
            double pass_rate = static_cast<double>(cls.at(0))/total_size;
            heap.push({double(total_size), pass_rate, double(cls.at(0))});
        }

        while (extraStudents){
            vector<double> cls = heap.top();
            cls.at(0)++;
            cls.at(2)++;
            heap.pop();
            heap.push({cls.at(0), cls.at(2)/cls.at(0), cls.at(2)});
            extraStudents--;
        }

        double ret = 0;
        while (!heap.empty()){
            ret += heap.top().at(1);
            cout<<heap.top().at(2)<<" "<<heap.top().at(0)-heap.top().at(2)<<endl;
            heap.pop();
        }

        return ret/classes.size();
    }*/

    double gain(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> heap;

        for (vector<int>& cls : classes) {
            int pass = cls.at(0);
            int total = cls.at(1);
            heap.push({gain(pass, total), pass, total});
        }

        while (extraStudents) {
            auto [currentGain, pass, total] = heap.top();
            heap.pop();
            pass++;
            total++;
            heap.push({gain(pass, total), pass, total});
            extraStudents--;
        }
        double ret = 0;
        while (!heap.empty()) {
            auto [_, pass, total] = heap.top();
            ret += (double)pass / total;
            heap.pop();
        }

        return ret/classes.size();
    }
};
