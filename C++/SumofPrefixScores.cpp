/*
class Solution {
public:
       Apparently, this question is too slow so it exceeds the time limit
       even though it's a correct and naive solution
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ret(words.size());

        for (int i = 0; i<words.size(); i++){
            int total = 0;
            for (int x = 0; x<words.at(i).size(); x++){
                string prefix = words.at(i).substr(0, x+1);
                int count = 0;
                for (int ii = 0; ii < words.size(); ii++) {
                    if (words.at(ii).rfind(prefix, 0) == 0) {
                        count++;
                    }
                }
                total += count;
            }
            ret.at(i) = total;
        }

        return ret;
    }
};  */

struct Node {
    int count = 0;
    Node* list[26] = {nullptr};
};

class Solution {
private:
    Node* root;

public:
    Solution() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (node->list[ch - 'a'] == nullptr) {
                node->list[ch - 'a'] = new Node();
            }
            node->list[ch - 'a']->count++;
            node = node->list[ch - 'a'];
        }
    }

    int search(const string& word) {
        Node* node = root;
        int preCount = 0;
        for (char ch : word) {
            preCount += node->list[ch - 'a']->count;
            node = node->list[ch - 'a'];
        }
        return preCount;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        for (auto& word : words) {
            insert(word);
        }

        int n = words.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int preCount = search(words[i]);
            res[i] = preCount;
        }

        return res;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
