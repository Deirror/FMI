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
    ListNode* reverseList(ListNode* head, int count) {
        if(!head || !head->next) {
            return head->next;
        }
        ListNode* first = head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        for(int i = 0; i < count; i++) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        first->next = curr;
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* res = head;
        for(int i = 1; i < left - 1; i++) {
            head = head->next;
        }
        int count = right - left;
        if(count + 1 > 1) {
            if(left > 1) {
                head->next = reverseList(head->next, count);;
            } else {
                return reverseList(head, count);
            }
        }
        return res;
    }
};
