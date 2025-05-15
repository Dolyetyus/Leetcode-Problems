class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ret;
        
        ret.push_back(words[0]);
        for (int i = 1; i < words.size(); i++) {
            if (groups.at(i) != groups.at(i-1)) ret.push_back(words.at(i));
        }

        return ret;
    }
};
