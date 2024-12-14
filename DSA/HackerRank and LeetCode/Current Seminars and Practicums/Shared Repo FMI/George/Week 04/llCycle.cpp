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
    bool hasCycle(ListNode *head) {
        const int visited = INT_MIN;
        while(head) {
            if(head->val == visited) {
                return true;
            }
            head->val = visited;
            head = head->next;
        }
        return false;
    }
};
