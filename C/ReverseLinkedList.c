struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* temp = NULL;
    struct ListNode* saved;

    while (head != NULL){
        saved = head->next;
        head->next = temp;
        temp = head;
        head = saved;
    }

    return temp;
}
