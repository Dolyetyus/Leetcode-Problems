class Solution {
public:
    // I have no idea how this problem is solved with bitmasking
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> hmap;
        hmap[0] = -1;

        int maxLen = 0;
        int mask = 0;
        const unordered_map<char, int> vowelMask = {
            {'a', 1}, {'e', 2}, {'i', 4}, {'o', 8}, {'u', 16}
        };

        for (int i = 0; i < s.size(); ++i) {
            if (vowelMask.count(s[i])) {
                mask ^= vowelMask.at(s[i]);
            }

            if (hmap.find(mask) == hmap.end()) {
                hmap[mask] = i;
            } 
            else {
                maxLen = max(maxLen, i - hmap[mask]);
            }
        }

        return maxLen;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
