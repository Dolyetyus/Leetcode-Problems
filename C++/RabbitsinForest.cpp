class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> hmap;
        int ret = 0;

        for (int num: answers) hmap[num]++;

        for (auto el: hmap){
            int groupSize = el.first+1;
            int groups = (el.second+groupSize-1)/groupSize;
            ret += groups*groupSize;
        }

        return ret;
    }
};
