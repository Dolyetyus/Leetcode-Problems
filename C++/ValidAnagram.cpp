class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;

        map<char, int> hmap1;
        map<char, int> hmap2;

        for (int i = 0; i<s.size(); i++){
            hmap1[s[i]]++;
            hmap2[t[i]]++;
        }

        return hmap1==hmap2;
    }
};
