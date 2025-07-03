class Solution {
public:
    char kthCharacter(int k) {
        vector<char> str = {'a'};
        int window = 1;
        while (window<k){
            for (int i = 0; i<window; i++){
                if (str.at(i)=='z') str.push_back('a');
                else str.push_back(str.at(i)+1);
            }
            window *= 2;
        }

        return str.at(k-1);
    }
};
