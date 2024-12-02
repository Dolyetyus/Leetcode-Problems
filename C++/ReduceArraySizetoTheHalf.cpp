class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> hmap;
        priority_queue<int> que;

        for (int num: arr){
            hmap[num]++;
        }

        for (auto i: hmap){
            que.push(i.second);
        }

        int remove = 0;
        int ret = 0;
        while (remove<arr.size()/2){
            remove+=que.top();
            que.pop();
            ret++;
        }

        return ret;
    }
};
