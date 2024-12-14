/*
 * Complete the 'removeDuplicates' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
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

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedList res;   
    SinglyLinkedListNode* prev = llist;
    llist = llist->next;
    while(llist) {
        if(prev->data != llist->data) {
            res.insert_node(prev->data);
            prev = llist;
        }
        llist = llist->next;
    }
    res.insert_node(prev->data);
    return res.head;
}
