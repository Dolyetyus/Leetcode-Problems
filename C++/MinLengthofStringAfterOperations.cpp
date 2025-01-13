class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> hmap;

        int total = 0;
        for (char chr: s){
            hmap[chr]++;
        }

        for (auto [chr, num]: hmap){
            if (num%2==0) total+=2;
            else total++;
        }

        return total;
    }
};
