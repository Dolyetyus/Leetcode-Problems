class Solution {
public:
int longestPalindrome(vector<string>& words) {
    int cnt[26][26] = {};
    for (const string& w : words)
        ++cnt[w[0]-'a'][w[1]-'a'];

    int res = 0;
    for (int a = 0; a < 26; ++a)
        for (int b = a+1; b < 26; ++b)
            res += 4 * min(cnt[a][b], cnt[b][a]);

    bool centreUsed = false;
    for (int a = 0; a < 26; ++a) {
        res += 4 * (cnt[a][a] / 2);
        if (!centreUsed && (cnt[a][a] & 1)) {
            res += 2;
            centreUsed = true;
        }
    }
    return res;
}
/* Time limit exceeded lol
    int longestPalindrome(vector<string>& words) {
        int ret = 0;
        map<string, int> hmap;
        int max = 0;
        map<string, vector<string>> indexmap;

        for (string word: words) {
            string sorted = word;
            if (word.at(0)>word.at(1)) {
                sorted.at(0) = word.at(1);
                sorted.at(1) = word.at(0);
            }
            if (word.at(0)==word.at(1)) {
                hmap[word]++;
                continue;
            }
            indexmap[sorted].push_back(word);
        }

        for (auto el: indexmap) {
            for (int i = 0; i<el.second.size(); i++){
                bool matched = false;
                for (int ii = i+1; ii<el.second.size(); ii++){
                    if (el.second.at(i).at(0)==el.second.at(ii).at(1) && 
                        el.second.at(i).at(1)==el.second.at(ii).at(0)){
                        ret+=4;
                        matched = true;
                        el.second.at(ii).at(1) = '0';
                        break;
                    }
                }
                if (matched) continue;
            }
        }

        bool putmid = false;
        for (auto el: hmap) {
            if (el.second%2==1 && el.second>max) {
                ret+=el.second*2;
                if (putmid) ret-=2;
                max = el.second;
                putmid = true;
            }
            else if (el.second%2==1) ret+=(el.second-1)*2;
            if (el.second%2==0) ret+=el.second*2;
        }

        return ret;
    }
*/
};
