class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> hmap; //Edit: I could have used a vector to make it much faster lmao
        int count = 0;
        int ret;

        for (auto beats: edges){
            hmap.insert(beats.at(1));
        }

        for (int i = 0; i<n; i++){
            if (hmap.count(i)==0){
                count++;
                ret = i;
            };
        }

        if (count!=1) return -1; 

        return ret;
    }
};
