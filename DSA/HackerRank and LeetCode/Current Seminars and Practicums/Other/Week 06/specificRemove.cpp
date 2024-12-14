#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void deletePenultimateAndPrint() {
        //TODO: implement this function
        if(!root || (!root->left && !root->right)) {
            return;
        }
        
        vector<int> valuesToDelete;
        dfsLowestParentsFind(root, valuesToDelete);
        for(int i = 0; i < valuesToDelete.size(); i++) {
            deleteNode(valuesToDelete[i]);
        }
        inorderTraversal(root);
    }

private:
    void inorderTraversal(Node* root) const {
        if(!root) {
            return;
        }
        inorderTraversal(root->left);
        cout << root->value << ' ';
        inorderTraversal(root->right);
    }
    
    bool dfsLowestParentsFind(Node* curr, vector<int>& vec) const {
        if(!curr || (!curr->left && !curr->right)) {
            return false;
        }
        
        bool leftFlag = dfsLowestParentsFind(curr->left, vec);
        bool rightFlag = dfsLowestParentsFind(curr->right, vec);
        
        if(!leftFlag && !rightFlag) {
            vec.push_back(curr->value);
        }
        
        return true;
    }
    
    Node** findMin(Node** subroot) {
        Node** curr = subroot;
        while((*curr)->left) {
            curr = &(*curr)->left;
        }
        return curr;
    }
    
      void deleteNode(int value) {
        Node** curr = &root;
        while(*curr) {
            if((*curr)->value < value) {
                curr = &(*curr)->right;
            } else if(value < (*curr)->value) {
                curr = &(*curr)->left;
            } else {
                break;
            }
        }
        if(*curr == nullptr) {
            return;
        }
        Node* toDelete = *curr;
        if(!toDelete->left && !toDelete->right) {
            *curr = nullptr;
        } else if(!toDelete->left && toDelete->right) {
            *curr = toDelete->right;
        } else if(toDelete->left && !toDelete->right) {
            *curr = toDelete->left;
        } else {
            Node** minRight = findMin(&(*curr)->right);
            
            *curr = *minRight;
            *minRight = (*minRight)->right;
            
            (*curr)->left = toDelete->left;
            (*curr)->right = toDelete->right;
        }
        delete toDelete;
    }
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    tree.deletePenultimateAndPrint();
    return 0;
}
