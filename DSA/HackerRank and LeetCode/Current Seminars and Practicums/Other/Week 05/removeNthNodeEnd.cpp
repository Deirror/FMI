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
        if(!head) {
            return head;
        }
        int size = getSize(head);

        if(size < n) {
            return head;
        }

        if(size == n) {
            return head->next;
        }

        ListNode* curr = head;
        int idx = size - n - 1;
        while(idx > 0) {
            curr = curr->next;
            --idx;
        }

        curr->next = curr->next->next;
        
        return head;
    }
};
