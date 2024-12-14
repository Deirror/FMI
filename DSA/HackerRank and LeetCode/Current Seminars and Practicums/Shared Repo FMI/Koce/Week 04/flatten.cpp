/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void recDLListFlattening(Node* curr, Node* prev_level) {
        bool flag = true;
        do {
            if(curr->child) {
                recDLListFlattening(curr->child, (!curr->next ? prev_level : curr->next));
                if(!curr->next) flag = false;
                curr->next = curr->child;
                curr->child->prev = curr;
            }
            curr->child = nullptr;
            if(curr->next) {
                curr = curr->next;
            } else {
                break;
            }
        } while(curr->next);
        if(flag) {
        curr->next = prev_level;
        if(prev_level)
        prev_level->prev = curr;
        }
    }

    Node* flatten(Node* head) {
        if(!head || (!head->next && !head->child)) {
            return head;
        }

        recDLListFlattening(head, nullptr);
        
        return head;
    }
};
