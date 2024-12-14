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
    bool checkNextNodes(ListNode*& curr) {
        bool flag = false;
        while(curr && curr->next && curr->val == curr->next->val) {
            curr = curr->next;
            flag = true;
        }
        return flag;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            bool check = false;
            while(checkNextNodes(curr)) {
                curr = curr->next;
                check = true;
            }

            if(check) {
                if(!prev) {
                    prev = curr;
                    head = prev;
                } else {
                    prev->next = curr;
                    prev = curr;
                }
            } else {
                prev = curr;
            }

            if(curr)
            curr = curr->next;           
        }
        return head;
    }
};
