class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ret;
        
        for (string& query: queries) {
            for (string& word: dictionary) {
                int diff = 0;
                for (int i = 0; i<query.length(); i++) {
                    if (query[i] != word[i]) diff++;
                    if (diff > 2) break;
                }
                
                if (diff <= 2) {
                    ret.push_back(query);
                    break;
                }
            }
        }
        
        return ret;
    }
};
