class Solution {
public:
    int buildChar(int charCount[26]) {
        int ret = 0;
        for (int i = 0; i < 26; i++) {
            if (charCount[i]) {
                ret++;
                charCount[i]--;
                ret += buildChar(charCount);
                charCount[i]++;
            }
        }
        return ret;
    }
    int numTilePossibilities(string tiles) {
        int charCount[26] = {0};
        for (char ch: tiles) {
            charCount[ch - 'A']++;
        }
        return buildChar(charCount);
    }
};
