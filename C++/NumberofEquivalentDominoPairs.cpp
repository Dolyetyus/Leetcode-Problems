class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> hmap;
        int ret = 0;

        for (vector<int> domino: dominoes){
            vector<int> temp;
            temp.push_back(domino.at(1));
            temp.push_back(domino.at(0));
            if (hmap[domino]) ret += hmap[domino];
            if (temp!=domino && hmap[temp]) ret += hmap[temp];
            hmap[domino]++;
        }

        return ret;
    }
};
