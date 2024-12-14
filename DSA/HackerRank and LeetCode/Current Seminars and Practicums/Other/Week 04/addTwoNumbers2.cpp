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
    static bool recAddLLValues(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) {
            return false;
        }
        bool add = recAddLLValues(l1->next, l2->next);
        int val = l1->val + l2->val;
        if(add) val++;
        l1->val = val;
        if(val / 10 > 0) {
            l1->val -= 10;
            return true;
        } else {
            return false;
        }
    }

    static bool recAddOneLL(ListNode* head, ListNode* end) {
        if(head == end) {
            return true;
        } 
        bool add = recAddOneLL(head->next, end);
        if(add) head->val++;

        if(head->val / 10 > 0) {
            head->val -= 10;
            return true;
        } else {
            return false;
        }
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) {
            return nullptr;
        } else if(!l1){
            return l2;
        } else if(!l2) {
            return l1;
        }
        int l1Size = getSize(l1);
        int l2Size = getSize(l2);

        if(l1Size < l2Size) {
            swap(l1, l2);
            swap(l1Size, l2Size);
        }

        ListNode* temp = l1;
        for(int i = 0; i < l1Size - l2Size; i++) {
            temp = temp->next;
        }

        bool add = recAddLLValues(temp, l2);
        if(add) {
            if(l1Size == l2Size) {
                ListNode* node = new ListNode(1, l1);
                l1 = node;
            } else {
                bool addL1 = recAddOneLL(l1, temp);
                if(addL1){
                ListNode* node = new ListNode(1, l1);
                l1 = node;
                }
            }
        }
        return l1;
    }
};
