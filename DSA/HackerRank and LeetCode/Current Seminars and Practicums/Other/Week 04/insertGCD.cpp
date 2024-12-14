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
    static int GCD(int a, int b) {
        int res = min(a, b);
        while (res > 1) {
            if (a % res == 0 && b % res == 0)
                break;
             res--;
        }
        return res;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* curr = head;
        while(curr->next) {
            ListNode* temp = curr->next;
            ListNode* node = new ListNode(GCD(temp->val, curr->val));
            curr->next = node;
            node->next = temp;
            curr = temp;
        }
        return head;
    }
};
