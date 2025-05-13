class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> hmap(26);

        for (char c: s) hmap.at(c-97)++;

        for (int i = 0; i<t; i++){
            int zcount = hmap.at(25)%1000000007;
            for (int ii = 24; ii>=0; ii--){
                hmap.at(ii+1) = hmap.at(ii);
            }
            hmap.at(0) = zcount;
            hmap.at(1) += zcount;
        }

        int ret = 0;
        for (int num: hmap) {
            ret += num%1000000007;
            ret %= 1000000007;
        }

        return ret;
    }
};
