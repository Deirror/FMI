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
    int getSize(ListNode* head) {
        int size = 0;
        while(head) {
            head = head->next;
            size++;
        }
        return size;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);

        if(size < n) {
            return head;
        } else if(size == n) {
            return head->next;
        } else {
            ListNode* curr = head;
            for(int i = 0; i < size - n - 1; i++) {
                curr = curr->next;
            }
            curr->next = curr->next->next;
        }
        return head;
    }
};
