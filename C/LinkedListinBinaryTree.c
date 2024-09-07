bool check(struct ListNode* head, struct TreeNode* root){
    if (head == NULL) return true;
    if (root == NULL) return false;

    /*if (head->val == root->val){
        if (check(head->next, root->left) || check(head->next, root->right)) {
            return true;
        }
    }*/

    return head->val == root->val && (check(head->next, root->left) || check(head->next, root->right));
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (!root) return false;
    return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}
