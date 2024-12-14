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
    static ListNode* reverseHalf(ListNode* mid) {
        ListNode* prev = nullptr;
        ListNode* curr = mid;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    static int getSize(ListNode* head) {
        int size = 0;
        while(head) {
            size++;
            head = head->next;
        }
        return size;
    }
public:
    int pairSum(ListNode* head) {
        if(!head) {
            return -1;
        }

        int size = getSize(head);
        int midSize = size / 2;
        ListNode* prev = nullptr;
        ListNode* mid = head; 
        for(int i = 0; i < midSize; i++) {
            prev = mid;
            mid = mid->next;
        }
        prev->next = nullptr;
        ListNode* revTail = reverseHalf(mid);
        int maxSum = 0;
         for(int i = 0; i < midSize; i++) {
            maxSum = max(maxSum, head->val + revTail->val);
            head = head->next;
            revTail = revTail->next;
         }
         return maxSum;
    }
};
