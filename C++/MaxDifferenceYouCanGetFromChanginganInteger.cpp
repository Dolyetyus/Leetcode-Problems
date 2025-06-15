class Solution {
public:
    int maxDiff(int num) {
        string max = to_string(num);
        string min = to_string(num);
        char replace9 ='-';
        char replace0 ='-';
        char replaceWith = '1';

        for (int i = 0; i<max.size(); i++){
            if (max[i]==replace9) max[i] = '9';
            else if (max[i]!='9' && replace9=='-'){
                replace9 = max[i];
                max[i] = '9';
            }

            if (min[i]==replace0) min[i] = replaceWith;
            else if (min[i]!='1' && min[i]!='0'&& replace0=='-'){
                if (i!=0 && replace0=='-'){
                    replaceWith = '0';
                }
                replace0 = min[i];
                min[i] = replaceWith;
            }
        }

        return stoi(max)-stoi(min);
    }
};
