class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ret;
        vector<int> hmap(10);
        vector<int> count(10);

        for (int num: digits) hmap.at(num)++;

        for (int i = 100; i<1000; i+=2){
            bool valid = true;
            count.at(i/100)++;
            count.at(i%10)++;
            count.at((i/10)%10)++;
            for (int x = 0; x<10; x++){
                if (count.at(x)>hmap.at(x)) {
                    valid = false;
                    break;
                }
            }
            for (int x = 0; x<10; x++) count.at(x) = 0;
            if (!valid) continue;
            ret.push_back(i);
        }

        return ret;
    }
};
