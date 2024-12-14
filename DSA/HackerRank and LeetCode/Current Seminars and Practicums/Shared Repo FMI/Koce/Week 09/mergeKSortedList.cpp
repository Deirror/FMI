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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < lists.size(); i++) {
            ListNode* curr = lists[i];
            while(curr) {
                pq.push(curr->val);
                curr = curr->next;
            }
        }
        if(pq.empty()) {
            return nullptr;
        }
        ListNode* res = new ListNode(pq.top());
        pq.pop();
        ListNode* curr = res;
        while(pq.size()) {
            curr->next = new ListNode(pq.top());
            curr = curr->next;
            pq.pop();
        }
        return res;
    }
};
