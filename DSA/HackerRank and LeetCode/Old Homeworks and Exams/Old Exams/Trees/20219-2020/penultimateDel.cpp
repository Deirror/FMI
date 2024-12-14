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
        if(!root) {
            return;
        }
        vector<int> vec;
        dfsFillVec(root, vec);
        for(auto value : vec) {
            deleteNode(value);
        }
        dfs(root);
    }
    
    void dfs(Node* root) {
        if(!root) {
            return;
        }
        dfs(root->left);
        cout << root->value << ' ';
        dfs(root->right);
    }

private:
    bool dfsFillVec(Node* root, vector<int>& vec) {
        if(!root || (!root->left && !root->right)) {
            return true;
        }
        
        bool fl = dfsFillVec(root->left, vec);
        bool df = dfsFillVec(root->right, vec);
        
        if(((root->left && root->right) || (!root->left && root->right) || (root->left && !root->right)) && fl && df) {
            vec.push_back(root->value);
        }
        
        return false;
    }
    
    Node** findMin(Node** subroot) {
        while((*subroot)->left) {
            subroot = &(*subroot)->left;
        }
        return subroot;
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
        } else if(toDelete->left && !toDelete->right) {
            *curr = (*curr)->left;
        } else if(!toDelete->left && toDelete->right) {
            *curr = (*curr)->right;
        } else {
            Node** minRight = findMin(&toDelete->right);
            
            *curr = *minRight;
            *minRight = (*minRight)->right;
            
            (*curr)->left = toDelete->left;
            (*curr)->right = toDelete->right;
        }
        delete toDelete;
    }
    
  	void findNodesToDelete(Node* root, vector<int>& vec) {
        
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
