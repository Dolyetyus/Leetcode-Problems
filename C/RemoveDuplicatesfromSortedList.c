/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head==NULL) return head;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy = head;

    while (head->next!=NULL){
        if (head->val == head->next->val){
            if (head->next->next != NULL) head->next = head->next->next;
            else head->next = NULL;
        }
        else head = head->next;
    }

    return dummy;
}
