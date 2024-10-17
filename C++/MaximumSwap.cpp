class Solution {
public:
    int maximumSwap(int num) {
        string str_num = to_string(num);
        int n = str_num.size();
        int last[10] = {0};

        for (int i = 0; i < n; i++) {
            last[str_num[i] - '0'] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int d = 9; d > str_num[i] - '0'; d--) {
                if (last[d] > i) {
                    swap(str_num[i], str_num[last[d]]);
                    return stoi(str_num);
                }
            }
        }

        return num;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
