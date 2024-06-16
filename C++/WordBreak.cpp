class Solution {
public:
        bool wordBreakHelper(const string& s, unordered_set<string>& wordSet, int start, unordered_map<int, bool>& memo) {
        if (start == s.size()) {
            return true;
        }
        
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }

        string seek = "";
        for (int i = start; i < s.size(); ++i) {
            seek += s[i];
            if (wordSet.find(seek) != wordSet.end() && wordBreakHelper(s, wordSet, i + 1, memo)) {
                memo[start] = true;
                return true;
            }
        }

        memo[start] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> memo;
        return wordBreakHelper(s, wordSet, 0, memo);
    }
};
