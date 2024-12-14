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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return head;
        if(!head->next) return nullptr;
        int size = 0;

       ListNode* slow = nullptr;
       ListNode* fast = head;
       while(fast && fast->next) {
            if(!slow) {
                slow = head;
            } else {
                slow = slow->next;
            }
            fast = fast->next->next;
       }
       slow->next = slow->next->next;
       return head;
    }
};
