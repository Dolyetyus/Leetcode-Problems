
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> path;
        int index = 0, n = traversal.size();

        int rootVal = 0;
        while (index < n && traversal[index] != '-') {
            rootVal = rootVal * 10 + (traversal[index] - '0');
            index++;
        }
        TreeNode* root = new TreeNode(rootVal);
        path.push(root);

        while (index < n) {
            int depth = 0;
            while (index < n && traversal[index] == '-') {
                depth++;
                index++;
            }

            int val = 0;
            while (index < n && traversal[index] != '-') {
                val = val * 10 + (traversal[index] - '0');
                index++;
            }

            while (path.size() > depth) {
                path.pop();
            }

            TreeNode* node = new TreeNode(val);
            TreeNode* parent = path.top();

            if (!parent->left) parent->left = node;
            else parent->right = node;

            path.push(node);
        }

        return root;
    }

    /*TreeNode* recoverFromPreorder(string traversal) {
        TreeNode* root = new TreeNode(traversal[0]-48);

        construct(traversal, root, 1);

        return root;
    }

    void construct(string traversal, TreeNode* root, int index){
        if (index>=traversal.size()) return;
        int depth = 0;

        while (traversal[index] == '-') {
            depth++;
            index++;
        }

        string num_str;
        while (traversal[index] != '-' && index<traversal.size()) {
            num_str.push_back(traversal[index]);
            index++;
        }
        int num = stoi(num_str);

        cout<<"Depth: "<<depth<<" Val: "<<num<<endl;
        
        fill(depth-1, root, num);
        construct(traversal, root, index);
    }

    void fill(int depth, TreeNode* root, int val){
        if (root == NULL) return;
        if (depth==0){
            if (root->left == NULL) {
                root->left = new TreeNode(val);
                return;
            }
            else if (root->right != NULL) {
                return;
            }
            else {
                root->right = new TreeNode(val);
                return;
            }
        }
        fill(depth-1, root->left, val);
        fill(depth-1, root->right, val);
    }*/
};
