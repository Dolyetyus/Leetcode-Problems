/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    struct ListNode* prev = NULL;
    struct ListNode** ret = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    *returnSize = k;
    int num_nodes = 0;
    struct ListNode* temp = head;
    
    while (temp != NULL) {
        num_nodes++;
        temp = temp->next;
    }

    int arr_size = num_nodes / k;
    int extra = num_nodes % k;
    temp = head;

    for (int i = 0; i < k; i++) {
        ret[i] = temp;
        int part_size = arr_size + (extra > 0 ? 1 : 0);
        extra--;

        for (int j = 0; j < part_size - 1; j++) {
            if (temp != NULL) {
                temp = temp->next;
            }
        }

        if (temp != NULL) {
            struct ListNode* next = temp->next;
            temp->next = NULL;
            temp = next;
        }
    }

    return ret;
}
