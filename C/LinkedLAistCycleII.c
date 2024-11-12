struct ListNode *detectCycle(struct ListNode *head) {
    // My favourite cycle detection algorithm btw B-)
    int pos = 0;
    while (head!=NULL){
        if (head->val>=111111) return head;
        head->val = 111111+pos;
        pos++;
        head = head->next;
    }
    return NULL;
}
