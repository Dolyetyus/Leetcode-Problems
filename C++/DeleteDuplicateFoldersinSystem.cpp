struct Node {
    map<string, Node*> children;
    string name;
    bool deleted = false;

    Node(string n = "") : name(n) {}
};

class Solution {
public:
    unordered_map<string, int> freq;

    void insert(Node* root, vector<string>& path) {
        for (string& folder : path) {
            if (!root->children.count(folder)) root->children[folder] = new Node(folder);
            root = root->children[folder];
        }
    }

    string serialize(Node* node) {
        if (node->children.empty()) return "";

        string key;
        for (auto& [name, child] : node->children) {
            key += "(" + name + serialize(child) + ")";
        }

        freq[key]++;
        return key;
    }

    void mark(Node* node) {
        if (node->children.empty()) return;

        string key;
        for (auto& [name, child]: node->children) {
            mark(child);
            key += "(" + name + serialize(child) + ")";
        }

        if (freq[key] > 1) node->deleted = true;
    }

    void collect(Node* node, vector<string>& path, vector<vector<string>>& ret) {
        if (node->deleted) return;

        if (!path.empty()) ret.push_back(path);

        for (auto& [name, child] : node->children) {
            path.push_back(name);
            collect(child, path, ret);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
         Node* root = new Node();

        for (auto& path : paths) {
            insert(root, path);
        }

        serialize(root);

        mark(root);

        vector<vector<string>> ret;
        vector<string> path;
        collect(root, path, ret);
        return ret;
    }
};
