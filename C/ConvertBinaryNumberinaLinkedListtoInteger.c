int getDecimalValue(struct ListNode* head) {
    int size = 0;
    int *arr = malloc(1*sizeof(int));
    int ret = 0;
    int keer = 1;

    while (head != NULL){
        size++;
        arr = realloc(arr, size*sizeof(int));
        arr[size-1] = head->val;
        head = head->next;
    }

    for (int i = size-1; i>=0; i--, keer*=2){
        if (arr[i]==1) ret += keer;
    }

    return ret;
}
