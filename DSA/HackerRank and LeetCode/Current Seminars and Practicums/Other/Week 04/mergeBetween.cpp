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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        //Ultra zashtita za tupi cases
        if(!list1 && !list2) return nullptr;
        if(!list1) return list2;
        if(!list2) return list1;
        if(a < 0 || b < 0) return list1;   

        ListNode* curr = list1;
        for(int i = 0; i < a - 1; i++) {
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = list2;
        while(list2->next) {
            list2 = list2->next;
        }
        for(int i = 0; i < b - a + 1; i++) {
            temp = temp->next;
        }
        list2->next = temp;

        return list1;
    }
};
