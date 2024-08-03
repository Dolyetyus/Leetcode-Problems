struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* newList = NULL;
    struct ListNode* currentNewList = NULL;
    int total = 0;
    head = head->next;

    while (head != NULL){
        if (head->val == 0){
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->val = total;
            newNode->next = NULL;

            if (newList == NULL) {
                newList = newNode;
                currentNewList = newNode;
            }
            else {
                currentNewList->next = newNode;
                currentNewList = newNode;
            }
            total = 0;
        }
        else{
            total += head->val;
        }
        head = head->next;
    }

    return newList;
}
