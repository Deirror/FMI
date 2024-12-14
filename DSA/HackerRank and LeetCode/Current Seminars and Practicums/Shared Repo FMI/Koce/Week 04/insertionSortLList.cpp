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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* prev_curr = head; 
        ListNode* curr = head->next;
        for(int i = 1; curr; i++) {
            int key = curr->val;
            ListNode* temp = head;
            ListNode* prev = nullptr;
            ListNode* step = curr->next;
            for(int j = 0; j < i; j++) {
                if(temp->val > key) {
                    if(prev){
                        prev->next = curr;
                    } else {
                        head = curr;
                    }
                    curr->next = temp;
                    prev_curr->next = step;
                    break;
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            prev_curr = (prev_curr->val >= curr->val) ? prev_curr : curr;
            curr = step;
        }
        return head;
    }
};
