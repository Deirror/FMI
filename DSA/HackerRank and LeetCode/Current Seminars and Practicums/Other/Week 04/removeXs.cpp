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
    ListNode* removeX(int x, ListNode* head) {
        ListNode** node = &head;
        while(*node) {
            if((*node)->val == x) {
                *node = (*node)->next;
            }
            else {
                 node = &(*node)->next;
            }
        }
        return head;
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head) {
            return nullptr;
        }
        for(auto x : nums) {
            head = removeX(x, head);
        }
        return head;
    }
};
