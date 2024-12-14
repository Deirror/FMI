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
            size++;
            head = head->next;
        }
        return size;
    }
public:
    void reorderList(ListNode* head) {
        int size = getSize(head);
        int mid = size / 2;
        if(size % 2) mid++;
        ListNode* curr = head;
        for(int i = 0; i < mid; i++) {
            ListNode* temp = curr;
            for(int j = 0; j < size - 2 * i - 1; j++) {
                curr = curr->next;
            }
            if(temp == curr) {
                curr->next = nullptr;
            } else {
                ListNode* next = temp->next;
                temp->next = curr;
                curr->next = next;
                curr = next;
            }
        }
        curr->next = nullptr;
    }
};
