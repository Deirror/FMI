struct ListNode {
	int value = 0;
	ListNode* next = nullptr;

	ListNode(int value, ListNode* next = nullptr) : value(value), next(next) {}
};

int getListSize(ListNode* head) {
	int size = 0;
	while (head) {
		head = head->next;
		size++;
	}
	return size;
}

// 0-indexed args
void reverseListInBetween(ListNode*& head, int start, int end) {
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

void reverseListInKParts(ListNode*& head, int k) {
	int size = getListSize(head);
	int parts = size / k;
	if (!parts || size == k) {
		return;
	}

	for (int i = 0; i < size; i += k) {
		reverseListInBetween(head, i, k + i - 1);
	}
}

void reverseList(ListNode*& head) {
	reverseListInBetween(head, 0, getListSize(head) - 1);
}
