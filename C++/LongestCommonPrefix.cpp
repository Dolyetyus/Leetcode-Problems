class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = 99999999;
        int min_len = 99999999;

        for (int i = 0; i<strs.size()-1; i++){
            if (strs.at(i).size()==0) return "";
            
            if (strs.at(i).size()<min_len) min_len = strs.at(i).size();

            int id = 0;
            while (strs.at(i)[id] == strs.at(i+1)[id] && id<min_len){
                id++;
            }

            len = min(id, len);
        }

        if (len==0) return "";
        return strs.at(0).substr(0, len);
    }
};
