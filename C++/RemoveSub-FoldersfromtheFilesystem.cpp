class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ret;

        for (string str: folder) {
            if (ret.empty() || str.substr(0, ret.back().size()) != ret.back() || str[ret.back().size()] != '/') {
                ret.push_back(str);
            }
        }

        return ret;
    }
};
