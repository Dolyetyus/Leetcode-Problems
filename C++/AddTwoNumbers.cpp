class Solution {
public:
    /*ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long rev_num1 = 0;
        long rev_num2 = 0;
        long num1 = 0;
        long num2 = 0;

        while (l1!=NULL){
            rev_num1 *= 10;
            rev_num1 += l1->val;
            l1 = l1->next;
        }

        while (l2!=NULL){
            rev_num2 *= 10;
            rev_num2 += l2->val;
            l2 = l2->next;
        }

        while (rev_num1!=0) {
            num1 = num1 * 10 + rev_num1 % 10;
            rev_num1 = rev_num1 / 10;
        }

        while (rev_num2!=0) {
            num2 = num2 * 10 + rev_num2 % 10;
            rev_num2 = rev_num2 / 10;
        }

        cout<<num1<<" "<<num2<<endl;

        long result = num1+num2;
        ListNode* res = new ListNode();
        ListNode* temp = res;

        while (result != 0) {
            temp->val = result % 10;
            result /= 10;
            if (result != 0) {
                temp->next = new ListNode();
                temp = temp->next;
            }
        }

        return res;
    }*/

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummyHead->next;
    }
};
