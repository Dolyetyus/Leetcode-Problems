class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> hmap;

        for (int i = 1; i<=n; i++) {
            int num = i;
            int digits = 0;

            while (num>0){
                digits += num%10;
                num /= 10;
            }
            hmap[digits]++;
        }

        int max = 0;
        int ret = 0;
        for (auto iter = hmap.begin(); iter != hmap.end(); ++iter) {
            if (iter->second > max) {
                max = iter->second;
                ret = 1;
            }
            else if (iter->second == max) ret++;
        }

        return ret;
    }
};
