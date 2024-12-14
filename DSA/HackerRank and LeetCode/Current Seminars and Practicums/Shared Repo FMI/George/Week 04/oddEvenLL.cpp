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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode* curr = head;
        ListNode* linker = nullptr;
        ListNode* toLink = nullptr;
        int counter = 1;
        while(curr->next) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            if(!curr->next) {
                if(counter % 2 == 0) {
                    toLink = temp;
                } else {
                    toLink = curr;
                }
            }
            curr = temp;
            if(!linker) {
                linker = curr;
            }
            counter++;
        }
        toLink->next = linker;
        return head;
    }
};
