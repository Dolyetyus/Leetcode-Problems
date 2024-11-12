bool hasCycle(struct ListNode *head) {
    // My favourite cycle detection algorithm btw B-)
    while (head!=NULL){
        if (head->val==-111111) return true;
        head->val = -111111;
        head = head->next;
    }
    return false;
}
