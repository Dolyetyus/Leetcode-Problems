struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head==NULL) return head;

    int len = 1;
    struct ListNode* ret = head;

    while (head->next!=NULL){
        head=head->next;
        len++;
    }

    k = k%len;
    if (k==0) return ret;

    head->next = ret;
    head = ret;
    int steps = len-k-1;
    while (steps>0){
        head=head->next;
        steps--;
    }

    ret = head->next;
    head->next = NULL;

    return ret;
}
