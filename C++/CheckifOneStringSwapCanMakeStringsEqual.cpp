class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char, int> hmap1;
        unordered_map<char, int> hmap2;

        for (int i = 0; i<s1.size(); i++){
            hmap1[s1[i]]++;
            hmap2[s2[i]]++;
        }

        if (hmap1 != hmap2) return false;

        int swaps = 0;
        for (int i = 0; i<s1.size(); i++){
            if (s1[i]!=s2[i]) swaps++;
        }

        return swaps<3;
    }
};
