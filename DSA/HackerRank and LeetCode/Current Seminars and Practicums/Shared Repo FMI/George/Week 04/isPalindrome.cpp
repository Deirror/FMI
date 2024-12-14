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
    ListNode* revreseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head) {
            return false;
        } else if(!head->next) {
            return true;
        }
        int size = 0;
        ListNode* temp = head;
        while(temp) {
            size++;
            temp = temp->next;
        }
        int mid = size / 2;
        temp = head;
        for(int i = 1; i < mid; i++) {
            temp = temp->next;
        }
        ListNode* halfNode = temp->next;
        temp->next = nullptr;

        if(size % 2 != 0) {
            halfNode = halfNode->next;
        }

        ListNode* revTail = revreseList(halfNode);

        while(revTail && head) {
            if(revTail->val != head->val) {
                return false;
            }
            revTail = revTail->next;
            head = head->next;
        }

        return true;
    }
};
