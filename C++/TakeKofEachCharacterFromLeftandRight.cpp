class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k==0) return 0;
        vector<int> freq = {0,0,0};

        for (char chr: s){
            if (chr=='a') freq.at(0)++;
            else if (chr=='b') freq.at(1)++;
            else freq.at(2)++;
        }

        for (int fr: freq){
            if (fr<k) return -1;
        }

        int left = 0, max_len = 0;
        vector<int> freq_window(3, 0);

        for (int right = 0; right<s.size(); right++){
            if (s[right]=='a') freq_window.at(0)++;
            else if (s[right]=='b') freq_window.at(1)++;
            else freq_window.at(2)++;

            while ((freq[0]-freq_window[0] < k) ||
                (freq[1]-freq_window[1] < k) ||
                (freq[2]-freq_window[2] < k)) {

                if (s[left]=='a') freq_window.at(0)--;
                else if (s[left]=='b') freq_window.at(1)--;
                else freq_window.at(2)--;
                left++;
            }

            max_len = max(max_len, right-left+1);
        }

        return s.size()-max_len;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
