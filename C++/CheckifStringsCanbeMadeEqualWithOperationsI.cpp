class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        map<char, int> even1, odd1, even2, odd2;
        
        for (int i = 0; i<s1.size(); i++) {
            if (i % 2 == 0) {
                even1[s1[i]]++;
                even2[s2[i]]++;
            } 
            else {
                odd1[s1[i]]++;
                odd2[s2[i]]++;
            }
        }
        
        return even1 == even2 && odd1 == odd2;
    }
};
