class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> hmap;
        int ret = -1;

        for (int i = 0; i<s.size(); i++) {
            for (int j = i+1; j <= s.size(); j++) {
                string temp = s.substr(i, j-i);
                bool valid = true;

                if (temp.size()>1){
                    for (int x = 0; x<temp.size()-1; x++){
                        if (temp[x] != temp[x+1]){
                            valid = false;
                            break;
                        }
                    }
                }

                if (valid) hmap[temp]++;
            }
        }

        for (auto& it: hmap) {
            if (it.second>2 && int(it.first.size())>ret){
                ret = it.first.size();
            }
        }

        return ret;
    }
};
