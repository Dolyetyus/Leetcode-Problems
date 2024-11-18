struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* ret = head;
    int len = 0;

    while (head!=NULL){
        head=head->next;
        len++;
    }

    head = ret;
    if (len-n == 0){
        return head->next;
    }

    n++;
    while (head->next!=NULL){
        if (len-n==0) break;
        head=head->next;
        n++;
    }

    head->next = head->next->next;

    return ret;
}
