void rec(SinglyLinkedListNode* llist) {
    if(!llist) {
        return;
    }
    rec(llist->next);
    cout << llist->data << '\n';
}

void reversePrint(SinglyLinkedListNode* llist) {
    rec(llist);
}
