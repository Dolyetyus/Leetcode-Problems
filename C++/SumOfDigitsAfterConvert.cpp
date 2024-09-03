class Solution {
public:
    int getLucky(string s, int k) {
        vector<int> vec;
        int num = 0;

        for (int i = 0; i < s.size(); i++){
            int char_val = s[i] - 'a' + 1;
            if (char_val >= 10){
                num += char_val / 10 + char_val % 10;
                vec.push_back(char_val / 10);
                vec.push_back(char_val % 10);
            } 
            else {
                num += char_val;
                vec.push_back(char_val);
            }
        }

        if (k==1) return num;

        while (k>0) {
            num = 0;
            for (int i = 0; i < vec.size(); i++){
                num += vec[i];
            }

            k--;
            if (k==0) break;

            vec.clear();
            while (num > 0) {
                vec.push_back(num % 10);
                num /= 10;
            }
        }

        return num;
    }
};
