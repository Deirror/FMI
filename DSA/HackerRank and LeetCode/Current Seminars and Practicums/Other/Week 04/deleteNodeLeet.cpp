/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        ListNode* curr = node;
        while(curr) {
            ListNode* next = curr->next;
            if(next) {
                curr->val = next->val;
                prev = curr;
                curr = curr->next;
            } else {
                prev->next = nullptr;
                break;
            }
        }
    }
};
