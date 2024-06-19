class Solution {
public:
    int mySqrt(int x) {
        long ret = 1;
        
        while (ret*ret<=x){
            ret++;
        }

        return ret-1;
    }
};
