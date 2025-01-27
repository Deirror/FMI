DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    while(llist) {
        DoublyLinkedListNode* temp = llist->next;
        llist->next = llist->prev;
        llist->prev = temp;
        if(!llist->prev) {
            break;
        }
        llist = llist->prev;
    }
    return llist;
}
