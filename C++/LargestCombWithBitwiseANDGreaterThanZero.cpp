class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        map<int, int> bitmap;
        for (int candidate: candidates){
            unsigned int count = 0;
            int pos = 0;
            while (candidate) {
                if ((candidate & 1) == 1) bitmap[pos]++;
                candidate >>= 1;
                pos++;
            }
        }

        unsigned ret = 0;
        for(auto it = bitmap.cbegin(); it != bitmap.cend(); ++it ) {
            if (it->second > ret) ret = it->second;
        }

        return ret;
    }
};
