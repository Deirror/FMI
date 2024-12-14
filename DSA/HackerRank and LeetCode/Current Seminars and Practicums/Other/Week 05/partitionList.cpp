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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* linker = nullptr;
        ListNode* newHead = nullptr;
        ListNode* lastGreater = nullptr;
        ListNode* lastLess = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* next = curr->next;
            if(curr->val >= x) {
                if(!linker) {
                    linker = curr;
                }
                if(!lastGreater) {
                    lastGreater = curr;
                }
                lastGreater->next = curr;
                lastGreater = curr;
            } else {
                if(!newHead) {
                    newHead = curr;
                }
                 if(!lastLess) {
                    lastLess = curr;
                }
                lastLess->next = curr;
                lastLess = curr;
            }
            curr = next;
        }

        if(!lastGreater || !lastLess) {
            return head;
        }

        lastGreater->next = nullptr;
        lastLess->next = linker;
        return newHead ? newHead : head;
    }
};
