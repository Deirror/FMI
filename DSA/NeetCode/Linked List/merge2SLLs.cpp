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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) {
            return list2;
        } else if(!list2) {
            return list1;
        }

        if(list1->val > list2->val) {
            swap(list1, list2);
        }

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* prev1 = list1;
        ListNode* prev2 = list2;

        while(temp1 && temp2) {
            if(temp1->val <= temp2->val) {
                prev1 = temp1;
                temp1 = temp1->next;
            } else {
                prev1->next = temp2;
                ListNode* next2 = temp2->next;
                while(next2 && temp1->val > next2->val) {
                    temp2 = next2;
                    next2 = next2->next;
                }               

                if(!next2) {
                    temp2->next = temp1;
                    return list1;
                }
                temp2->next = temp1;
                prev2 = temp2;
                temp2 = next2;
            }
        }

        if(!temp1) {
            prev1->next = temp2;
        } else if(!temp2) {
            prev2->next = temp1;
        }

        return list1;
    }
};
