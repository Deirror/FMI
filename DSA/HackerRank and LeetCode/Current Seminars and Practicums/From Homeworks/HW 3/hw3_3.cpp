/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
            SinglyLinkedListNode* prev = nullptr;
            SinglyLinkedListNode* curr = llist;

            for (size_t i = 0; i < position; i++) {
                if (!curr) {
                    return llist;
                }
                prev = curr;
                curr = curr->next;
            }

            SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
            node->next = curr;
            prev->next = node;
    return llist;
}
