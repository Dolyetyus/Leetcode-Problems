struct TreeNode* sortedArrayToBSTHelper(int* nums, int start, int end) {
    if (start > end) return NULL;

    int mid = start + (end - start) / 2;
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = nums[mid];

    node->left = sortedArrayToBSTHelper(nums, start, mid - 1);
    node->right = sortedArrayToBSTHelper(nums, mid + 1, end);

    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (nums==NULL) return NULL;

    return sortedArrayToBSTHelper(nums, 0, numsSize - 1);
}
