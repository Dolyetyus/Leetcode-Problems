class Solution {
public:
    // Optimised solution
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXOR(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }
        
        vector<int> ret;
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            ret.push_back(prefixXOR[right + 1] ^ prefixXOR[left]);
        }
        
        return ret;
    }
    /*
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ret;

        for (auto query: queries){
            int left = query[0];
            int right = query[1];
            int res = arr[left];
            while (left<right){
                res ^= arr[left+1];
                left++;
            }
            ret.push_back(res);
        }

        return ret;
    }*/
};

static const int KDS = []() {
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
std::cout.tie(nullptr);
return 0;
}();
