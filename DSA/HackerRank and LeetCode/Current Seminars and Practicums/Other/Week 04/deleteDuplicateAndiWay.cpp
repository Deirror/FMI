SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if(!llist) {
        return nullptr;
    }
    SinglyLinkedListNode** curr = &llist;
    int prevData = -1;
    while(*curr) {
        if((*curr)->data == prevData) {
            *curr = (*curr)->next;
        } else {
            prevData = (*curr)->data;
            curr = &(*curr)->next;
        }
    }
    return llist;
}
