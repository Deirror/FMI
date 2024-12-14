/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if(!llist->next) {
        return nullptr;
    } else if (!position) {
        return llist->next;
    } else {
        SinglyLinkedListNode* prev = nullptr;
        SinglyLinkedListNode* curr = llist;
            
        for(int i = 0; i < position; i++) {
            prev = curr;
            curr = curr->next;
            if(!curr) {
                return nullptr;
            }
        }    
        
        prev->next = curr->next;
        delete curr;
        return llist;
    }
}
