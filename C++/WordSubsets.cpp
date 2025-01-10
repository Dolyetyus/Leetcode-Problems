class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> maxFreq;

        for (string word: words2) {
            unordered_map<char, int> tempFreq;
            for (char chr: word) {
                tempFreq[chr]++;
                maxFreq[chr] = max(maxFreq[chr], tempFreq[chr]);
            }
        }

        vector<string> ret;
        for (string word: words1){
            unordered_map<char, int> comp;
            for (char chr: word){
                comp[chr]++;
            }

            bool inc = true;
            for (auto& [chr, freq]: maxFreq) {
                if (comp[chr] < freq) {
                    inc = false;
                    break;
                }
            }

            if (inc) ret.push_back(word);
        }

        return ret;
    }
};
