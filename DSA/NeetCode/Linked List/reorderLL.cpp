

class Solution {
public:
    static void recOrderLL(ListNode*& slow, ListNode* fast) {
        if (!fast) {
            return;
        }
        recOrderLL(slow, fast->next);
        fast->next = slow->next;
        ListNode* next = slow->next;
        slow->next = fast;
        slow = next;;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = head;
        recOrderLL(curr, slow->next);

        slow->next = nullptr;
    }
};
