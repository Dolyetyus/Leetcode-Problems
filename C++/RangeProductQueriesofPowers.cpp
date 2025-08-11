class Solution {
public:
int X = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>result;
        vector<int>powers;

        for(int i = 0; i < 32; i++){
            if((n & (1 << i)) != 0){
                powers.push_back(1 << i);
            }
        }
        for(auto &q : queries){
            int s = q[0];
            int e = q[1];

            long product = 1;
            for(int i = s; i <= e; i++){
                product = (product * powers[i]) % X;
            }
            result.push_back(product);
        }
        return result;
    }
};
