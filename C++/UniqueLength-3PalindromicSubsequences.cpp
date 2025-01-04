class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, int> first, last;

        for (int i = 0; i < n; i++) {
            if (first.find(s[i]) == first.end()) first[s[i]] = i;
            last[s[i]] = i;
        }

        int ret = 0;
        for (auto& [ch, start] : first) {
            int end = last[ch];
            if (end - start > 1) {
                unordered_set<char> middle_chars;
                for (int i = start + 1; i < end; i++) {
                    middle_chars.insert(s[i]);
                }
                ret += middle_chars.size();
            }
        }

        return ret;
    }

    /*  O(n^3) brute force lmao
    int countPalindromicSubsequence(string s) {
        unordered_set<string> hset;
        for (int i = 0; i<s.size(); i++){
            for (int ii = i+2; ii<s.size(); ii++){
                if (s[i]==s[ii]){
                    for (int n = i+1; n<ii; n++){
                        string temp;
                        temp.push_back(s[i]);
                        temp.push_back(s[n]);
                        temp.push_back(s[ii]);
                        hset.insert(temp);
                    }
                }
            }
        }

        return hset.size();
    }
    */
};
