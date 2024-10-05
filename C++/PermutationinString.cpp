class Solution {
public:
    /* This is a very fucked up, non-optimised solution I came up with lol
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> hmap;
        int s1Size = s1.size();
        int s2Size = s2.size();

        for (char chr : s1) {
            hmap[chr]++;
        }

        for (int i = 0; i <= s2Size - s1Size; i++) {
            unordered_map<char, int> copy = hmap;
            int j = 0;
            for (; j < s1Size; j++) {
                if (copy.find(s2[i + j]) == copy.end()) {
                    break;
                } 
                else {
                    copy[s2[i+j]]--;
                    if (copy[s2[i + j]] == 0) {
                        copy.erase(s2[i + j]);
                    }
                }
            }
            if (j == s1Size) {
                return true;
            }
        }

        return false;
    }*/

    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.size();
        int s2Size = s2.size();

        if (s1Size > s2Size) {
            return false;
        }

        unordered_map<char, int> s1Map, s2Map;
        
        for (char chr : s1) {
            s1Map[chr]++;
        }
        
        for (int i = 0; i < s1Size; i++) {
            s2Map[s2[i]]++;
        }
        
        if (s1Map == s2Map) {
            return true;
        }
        
        for (int i = s1Size; i < s2Size; i++) {
            s2Map[s2[i]]++;
            s2Map[s2[i - s1Size]]--;
            if (s2Map[s2[i - s1Size]] == 0) {
                s2Map.erase(s2[i - s1Size]);
            }
            
            if (s1Map == s2Map) {
                return true;
            }
        }
        
        return false;
    }
};
