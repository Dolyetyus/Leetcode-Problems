class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int x = 1;
        for (int i=0; i<n; i++){
            ret.at(i) = x;
            if (x*10 > n){
                if (x==n) x/=10;
                x++;
                while(x%10==0) x/=10;
            } 
            else x*=10;          
        }
        return ret;
    }
};
