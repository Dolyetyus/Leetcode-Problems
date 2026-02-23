class TrieNode {
public:
    TrieNode* children[2];
    bool isEnd;

    TrieNode() {
        children[0] = children[1] = nullptr;
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;
    int uniqueCount;

public:
    Trie() {
        root = new TrieNode();
        uniqueCount = 0;
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c: word) {
            int index = c - '0'; 
            if (!node->children[index]) node->children[index] = new TrieNode();
            node = node->children[index];
        }

        if (!node->isEnd) {
            node->isEnd = true;
            uniqueCount++;
        }
    }

    int getUniqueCount() const {
        return uniqueCount;
    }
};

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();

        if (n < k) return false;

        Trie trie;
        for (int i = 0; i <= n-k; i++) {
            string sub = s.substr(i, k);
            trie.insert(sub);
        }

        int totalPossible = 1 << k;

        return trie.getUniqueCount() == totalPossible;
    }
};
