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
        } else if (!list2) {
            return list1;
        }

        if(list1->val > list2->val) {
            swap(list1, list2);
        }

        ListNode* head = list1;
        ListNode* prev = nullptr;
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                prev = list1;
                list1 = list1->next;
            } else {
                ListNode* temp = list2->next;
                list2->next = list1;
                prev->next = list2;
                prev = list2;
                list2 = temp;
            }
        }
       
        if(list2) {
            prev->next = list2;
        }

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return nullptr;
        } else if (lists.size() == 1) {
            return lists[0];
        }

        ListNode* res = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
};
