 struct ListNode {
     int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 ListNode* deleteNodes(ListNode* head, int target, bool(*pred)(ListNode*)) {
     if (!head) {
         return nullptr;
     }

     ListNode** ptrToPtrOfCurr = &head;
     while (*ptrToPtrOfCurr) {
         if (pred(*ptrToPtrOfCurr)) {
             ListNode* toDel = *ptrToPtrOfCurr;
             *ptrToPtrOfCurr = toDel->next;
             delete toDel;
         }
         else {
             ptrToPtrOfCurr = &(*ptrToPtrOfCurr)->next;
         }
     }
     return head;
 }
 
int main() {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(6);

    head = deleteNodes(head, 6, [](ListNode* node) -> bool {return node->val == 6;});
    
    return 0;
}
