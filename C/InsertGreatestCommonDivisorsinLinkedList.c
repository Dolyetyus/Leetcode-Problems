/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int gcd(int a, int b){
    int result;
    if (a>b) result = b;
    else result = a;

    while (result > 0) { 
        if (a % result == 0 && b % result == 0) { 
            break; 
        } 
        result--; 
    } 
  
    return result; 
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode* ret;
    ret = head;

    while (head->next != NULL){
        int result = gcd(head->val, head->next->val);

        struct ListNode *new_insert = malloc(sizeof(struct ListNode));
        struct ListNode* temp;
        new_insert->val = result;
        temp = head->next;
        head->next = new_insert;
        new_insert->next = temp;

        head = head->next->next;
    }

    return ret;
}
