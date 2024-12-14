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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k) {
            return head;
        }

        int size = 0;
        ListNode* tmp = head;
        while(tmp) {
            size++;
            tmp = tmp->next;
        }

        ListNode* old_head = head;
        ListNode* curr = head;

        k = k % size;

        if(!k) {
            return head;
        }

        for(int i = 0; i < size - k - 1; i++) {
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = nullptr;
        head = temp;
        curr = temp;
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = old_head;
        return head;
    }
};
