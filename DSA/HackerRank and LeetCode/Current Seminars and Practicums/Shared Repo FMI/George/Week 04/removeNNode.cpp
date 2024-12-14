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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head ||(!head->next && n == 1)) {
            return nullptr;
        }

        int size = 0;
        ListNode* temp = head;
        while(temp) {
            size++;
            temp = temp->next;
        }

        if(size < n) {
            return head;
        }

        if(size - n == 0) {
            return head->next;
        }

        int count = size - n;
        ListNode* prev = head;
        ListNode* curr = head->next;
        for(int i = 1; i < count; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        return head;
    }
};
