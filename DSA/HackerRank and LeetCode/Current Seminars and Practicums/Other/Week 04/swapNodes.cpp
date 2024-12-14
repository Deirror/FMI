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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next || !k) {
            return head;
        }

        int size = 0;
        ListNode* tmp = head;
        while(tmp) {
            size++;
            tmp = tmp->next;
        }

        if(size < k) {
            return head;
        }

        int left_idx = k;
        int right_idx = size - k + 1;

        ListNode* left = head;
        ListNode* right = head;
        for(int i = 0; i < size; i++) {
            if(i < left_idx - 1) {
                 left = left->next;
            }

            if(i < right_idx - 1) {
                right = right->next;
            }
        }

        swap(left->val, right->val);
        return head;
    }
};
