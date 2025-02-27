class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        if (arr.size()<3) return 0;
        set<int> hset;
        int ret = 2;

        for (int num: arr){
            hset.insert(num);
        }

        for (int i = 0; i<arr.size()-1; i++){
            int first = arr.at(i);
            int second = 0;
            
            for (int ii = i+1; ii<arr.size(); ii++){
                int temp = 2;
                int first = arr.at(i);
                if (hset.contains(first+arr.at(ii))) {
                    second = arr.at(ii);
                }

                if (second == 0) continue;

                while (hset.contains(first+second)){
                    int swap = first;
                    first = second;
                    second = swap+second;
                    temp++;
                }

                ret = max(temp, ret);
            }            
        }

        if (ret>2) return ret;
        return 0;
    }
};
