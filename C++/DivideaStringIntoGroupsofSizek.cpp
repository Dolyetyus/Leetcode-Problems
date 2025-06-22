class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ret;
        int addx = s.size()%k;

        for (int i = 0; i<s.size(); i+=k){
            string append;
            for (int ii = i; ii<i+k; ii++){
                if (ii==s.size()) break;
                append.push_back(s.at(ii));
            }
            ret.push_back(append);
        }

        if (addx!=0) {
            for (int i = 0; i<k-addx; i++){
                ret.at(ret.size()-1).push_back(fill);
            }
        }

        return ret;
    }
};
