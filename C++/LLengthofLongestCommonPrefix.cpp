class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;
        int longest = 0;
        
        for (int i = 0; i<arr1.size(); i++){
            string num = to_string(arr1.at(i));
            for (int x = 0; x<num.size(); x++){
                prefixes.insert(num.substr(0, x+1));
            }
        }

        for (int i = 0; i<arr2.size(); i++){
            string num = to_string(arr2.at(i));
            for (int x = 0; x<num.size(); x++){
                if (prefixes.find(num.substr(0, x+1)) == prefixes.end()){
                    break;
                }
                else{
                    longest = max(x+1, longest);
                }
            }
        }

        return max(longest, 0);
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
