/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:/*
    void insert(TreeNode* root, int number) {
        if (root == NULL) {
            root = new TreeNode();
            root->val = number;
        }
        else if (number < root->val) {
            if (root->left == NULL) {
                root->left = new TreeNode();
                root->left->val = number;
            } 
            else {
                insert(root->left, number);
            }
        }
        else {
            if (root->right == NULL) {
                root->right = new TreeNode();
                root->right->val = number;
            } 
            else {
                insert(root->right, number);
            }
        }
    }*/

    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = sortedArrayToBSTHelper(nums, start, mid - 1);
        node->right = sortedArrayToBSTHelper(nums, mid + 1, end);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;

        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
};
