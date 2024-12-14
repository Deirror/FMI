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
    int getSize(ListNode* head) {
        int size = 0;
        while(head) {
            head = head->next;
            size++;
        } return size;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int size = getSize(head);
        vector<int> answer(size, 0);
        stack<int> ms;
        for(int i = 0; i < size; i++) {
            int j = i - 1;
            while(!ms.empty() && ms.top() < head->val) {
                if(answer[j] == 0) {
                    answer[j] = head->val;
                    ms.pop();
                }
                j--;
            }
            ms.push(head->val);
            head = head->next;
        }
        return answer;
    }
};
