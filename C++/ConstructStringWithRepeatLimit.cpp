class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;
        for (char chr: s) {
            freq[chr]++;
        }

        priority_queue<pair<char, int>> heap;
        for (auto& entry: freq) {
            heap.push({entry.first, entry.second});
        }

        string ret;
        while (!heap.empty()){
            if (heap.top().second>repeatLimit){
                for (int i = 0; i<repeatLimit; i++){
                    ret.push_back(heap.top().first);
                }
                pair<char, int> temp1 = heap.top();
                temp1.second -= repeatLimit;
                heap.pop();

                if (!heap.empty()) {
                    ret.push_back(heap.top().first);
                    pair<char, int> temp2 = heap.top();
                    temp2.second--;
                    heap.pop();

                    if (temp1.second > 0) {
                        heap.push(temp1);
                    }
                    if (temp2.second > 0) {
                        heap.push(temp2);
                    }
                }
            }
            else{
                for (int i = 0; i<heap.top().second; i++){
                    ret.push_back(heap.top().first);
                }
                heap.pop();
            }
        }

        return ret;
    }
};
