void SinglyLinkedList::replace(int X) {
	Node* curr = this->head;
    int pos = 0;
    while(curr) {
        if(curr->value == X) {
            curr = curr->next;
            remove(pos);
            for(int i = 1; i <= X; i++) {
                add(1, pos);
                pos++;
            }
            
        } else {
            pos++;
            curr = curr->next;
        }
    }
    
}
