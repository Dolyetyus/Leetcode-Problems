class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size()<k) return false;
        unordered_map<char, int> hmap;

        for (char chr: s){
            hmap[chr]++;
        }

        int odds = 0;
        for (auto& [chr, num]: hmap){
            if (num%2==1) odds++;
        }

        if (odds>k) return false;
        return true;
    }
};
