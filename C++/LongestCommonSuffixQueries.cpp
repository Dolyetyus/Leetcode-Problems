class Solution {
public:
    struct Trie {
        map<char, Trie*> child;
        int index;
        int len;

        Trie() {
            index = INT_MAX;
            len = INT_MAX;
        }
    };

    void insert(Trie* node, string& s, int index) {
        int len = s.size();

        if (node->len > len) {
            node->len = len;
            node->index = index;
        } 
        else if (node->len == len) node->index = min(node->index, index);

        for (int i = len-1; i >= 0; i--) {
            char& c = s[i];

            if (!node->child.count(c)) node->child[c] = new Trie();
    
            node = node->child[c];
            if (node->len > len) {
                node->len = len;
                node->index = index;
            } 
            else if (node->len == len) node->index = min(node->index, index);
        }
    }
    int search(Trie* node, string& s) {
        int ret = 0;

        for (int i = s.size()-1; i >= 0; i--) {
            char& c = s[i];
            if (!node->child.count(c)) break;
            node = node->child[c];
        }

        ret = node->index;
        return ret;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        Trie* root = new Trie();
        unordered_map<string, int> cache;
    
        for (int i = 0; i < n; i++) {
            string& s = wordsContainer[i];
            if (cache.find(s) == cache.end()) {
                insert(root, s, i);
                cache[s] = 1;
            }
        }

        vector<int> ret;
        cache.clear();
        for (auto& s: wordsQuery) {
            if (cache.find(s) == cache.end()) cache[s] = search(root, s);
            ret.push_back(cache[s]);
        }

        return ret;
    }
};
