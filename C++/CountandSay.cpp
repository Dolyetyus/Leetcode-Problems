class Solution {
public:
    string countAndSay(int n) {
        return recursive(n, 1, "1");
    }

    string recursive(int n, int depth, string str){
        if (n==depth) return str;

        string ret;
        char prev = str.at(0);
        int count = 0;
        for (int i = 0; i<str.size(); i++){
            if (prev!=str.at(i)){
                ret.push_back(count+48);
                ret.push_back(prev);
                prev = str.at(i);
                count = 1;
            }
            else{
                count++;
            }
        }

        ret.push_back(count+48);
        ret.push_back(str.at(str.size()-1));

        return recursive(n, depth+1, ret);
    }
};
