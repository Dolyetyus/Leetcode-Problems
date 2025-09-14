class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    string devowel(string s) {
        for (char &c : s) {
            if (isVowel(c)) c = '*';
            else c = tolower(c);
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> cap;
        unordered_map<string,string> vow;

        for (string w: wordlist) {
            string lower;
            for (char c: w) lower.push_back(tolower(c));
            if (!cap.count(lower)) cap[lower] = w;

            string dv = devowel(w);
            if (!vow.count(dv)) vow[dv] = w;
        }

        vector<string> ans;
        for (string q: queries) {
            if (exact.count(q)) ans.push_back(q);
            else {
                string lower;
                for (char c: q) lower.push_back(tolower(c));
                if (cap.count(lower)) ans.push_back(cap[lower]);
                else {
                    string dv = devowel(q);
                    if (vow.count(dv)) ans.push_back(vow[dv]);
                    else ans.push_back("");
                }
            }
        }
        return ans;
    }

    /*
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ret;

        for (string word: queries) {
            string w = "";
            bool firstOcc = false;
            for (string match: wordlist) {
                int exact = 0;
                int other = 0;
                int non = 0;
            
                if (word.size()!=match.size()) continue;
                for (int i = 0; i<word.size(); i++) {
                    if (!checkVowel(word[i])) {
                        if (abs(word[i]-match[i])==0) exact++;
                        else if (abs(word[i]-match[i])==32) other++;
                        else non++;
                    }
                }

                if (non==0) {
                    if (other==0) {
                        bool really = true;
                        for (int i = 0; i<word.size(); i++) {
                            if (abs(word[i]-match[i])!=0) really = false;
                        }
                        if (really) {
                            w = word;
                            break;
                        }
                    }
                    else if (!firstOcc){
                        firstOcc = true;
                        w = match;
                    }
                }
            }

            ret.push_back(w);
        }

        return ret;
    }
    */
};
