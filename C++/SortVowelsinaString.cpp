class Solution {
public:
    bool isvowel(char v) {
        return (0x208222>>(v&0x1f))&1;
    }

    string sortVowels(string s) {
        vector<char> vowels;
        int id = 0;

        for (int i = 0; i<s.size(); i++){
            if (isvowel(s[i])) vowels.push_back(s[i]);
        }

        sort(vowels.begin(), vowels.end());

        for (int i = 0; i<s.size(); i++){
            if (isvowel(s[i])) {
                s[i] = vowels[id];
                id++;
            } 
        }

        return s;
    }
};
