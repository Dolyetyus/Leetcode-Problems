/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> sorted;

    void traverse(Node* root){
        if (root == NULL) {
            return;
        }

        for (int i = 0; i<root->children.size(); i++){
            traverse(root->children.at(i));
        }
        sorted.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        traverse(root);
        return sorted;
    }
};
