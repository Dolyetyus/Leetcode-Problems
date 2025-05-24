class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ret;
        for (int i = 0; i<words.size(); i++){
            for (char chr: words.at(i)) if (chr==x) {
                ret.push_back(i);
                break;
            }
        }

        return ret;
    }
};
