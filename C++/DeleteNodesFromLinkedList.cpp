/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /* Idk why I made my first approach extremely complicated
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
            std::set<int> hmap(nums.begin(), nums.end());
            ListNode* prev = NULL;
            ListNode* ret = head;

            while (head != NULL){
                if (hmap.contains(head->val))
                    head = removeNode(head, prev, ret);
                else {
                    prev = head;
                    head = head->next;
                }
            }

            return ret;
    }

    ListNode* removeNode(ListNode* head, ListNode* prev, ListNode*& ret) {
        ListNode* nextNode = head->next;
        if (prev == NULL) {
            ret = nextNode;
        } 
        else {
            prev->next = nextNode;
        }
        delete head;
        return nextNode;
    }*/

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        std::unordered_set<int> hmap(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        while (current->next != nullptr) {
            if (hmap.find(current->next->val) != hmap.end()) {
                current->next = current->next->next;
            } 
            else {
                current = current->next;
            }
        }

        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};
