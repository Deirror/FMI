SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    if(!llist) {
        return llist;
    }
    
    if(!position) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
        node->next = llist;
        llist = node;
        return llist;
    }
    
    SinglyLinkedListNode* curr = llist;
    for(int i = 1; i < position && curr; i++) {
        curr = curr->next;
    }
    
    if(!curr) {
        return llist;
    }
    
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    if(!curr->next) {
        curr->next = node;
        node->next = nullptr;
    } else {
        SinglyLinkedListNode* nextNext = curr->next;
        curr->next = node;
        node->next = nextNext;
    }
    
    return llist;
}
