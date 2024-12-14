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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        vector<int> vec_nodes;
        ListNode* temp = head;
        while(temp) {
            vec_nodes.push_back(temp->val);
            temp = temp->next;
        }
        sort(vec_nodes.begin(), vec_nodes.end());
        temp = head;
        for(auto num : vec_nodes) {
            temp->val = num;
            temp = temp->next;
        }
        return head;
    }
};
