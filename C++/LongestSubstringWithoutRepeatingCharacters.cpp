class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()<2) return s.size();

        int ret = 0;
        for (int i = 0; i<s.size()-1; i++){
            int size = 0;
            unordered_map<char, int> hashmap;
            for (int ii = i; ii<s.size(); ii++){
                map<char, int>::iterator it;
                if (hashmap.find(s[ii]) != hashmap.end()){  
                    break;
                }
                else{
                    hashmap[s[ii]] = 1;
                    size++;
                }
            }
            ret = max(size, ret);
        }
        return ret;
    }
};
