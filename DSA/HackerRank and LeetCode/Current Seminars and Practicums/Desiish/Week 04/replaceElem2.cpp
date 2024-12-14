void SinglyLinkedList::replace(int X)
{
    if(X >= size) {
        return;
    }
	Node* curr = head;

    for(int i = 0; i < X; i++) {
        curr = curr->next;
    }
    if(!curr) {
        return;
    }    
    int Y = curr->value;
    
    curr = head;
    while(curr->next) {
        if(curr->value == Y) {
            curr->value = curr->next->value;
        }
        curr = curr->next;
    }
}
