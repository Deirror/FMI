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
    static void reverseListBetween(ListNode*& head, int start, int end) {
	if (!head || !head->next) {
		return;
	}

	if (start < 0 || end < 0) {
		return;
	}

	if (start > end) {
		swap(start, end);
	}

	ListNode* prev = nullptr;
	ListNode* startListNode = head;
	for (int i = 0; i < start && startListNode; i++) {
		prev = startListNode;
		startListNode = startListNode->next;
	}

	ListNode* endListNode = startListNode;
	int times = end - start;
	while (times && endListNode) {
		endListNode = endListNode->next;
		times--;
	}

	if (!endListNode && times) {
		return;
	}

	ListNode* afterEnd = nullptr;
	if (endListNode || times) {
		afterEnd = endListNode->next;
	}

	ListNode* temp = afterEnd;
	while (startListNode != afterEnd) {
		ListNode* next = startListNode->next;
		startListNode->next = temp;
		temp = startListNode;
		startListNode = next;
	}

	if (prev) {
		prev->next = endListNode;
	} else {
		head = endListNode;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) {
            return head;
        }
        int size = getSize(head);
        int times = size / k;
        if(!times) {
            return head;
        }
        for(int i = 0, j = 0; i < times; i++, j+=k) {
            reverseListBetween(head, j, k + j - 1);
        }
        return head;
    }
};
