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
    ListNode* middleNode(ListNode* head) {
        ListNode* beg = head;
        int count = 0;
        while(head) {
            count++;
            head = head->next;
        }
        int mid = count / 2;
        if(count % 2 != 0) mid++;
        for(int i = 0; i < count - mid; i++) {
            beg = beg->next;
        }
        return beg;
    }
};
