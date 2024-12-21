#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data, Node* left = nullptr, Node* right = nullptr) 
        : data(data), left(left), right(right) {}
};

class BST {
    Node* root = nullptr;
    
    void CLD(Node* root) const {
        if(!root) {
            return;
        }
        cout << root->data << ' ';
        CLD(root->left);
        CLD(root->right);
    }
    
    Node** findMin(Node** node) const {
        while((*node)->left) {
            node = &(*node)->left;
        }
        return node;
    }
public:
    void add(int data) {
        Node** curr = &root;
        while(*curr) {
            if((*curr)->data < data) {
                curr = &(*curr)->right;
            } else if(data < (*curr)->data) {
                curr = &(*curr)->left;
            } else {
                return;
            }
        }
        *curr = new Node(data);
    }  
    
    void remove(int data) {
        Node** curr = &root;
        while(*curr) {
            if((*curr)->data < data) {
                curr = &(*curr)->right;
            } else if(data < (*curr)->data) {
                curr = &(*curr)->left;
            } else {
                break;
            }
        }
        if(!(*curr)) {
            return;
        }
        Node* toRemove = *curr;
        if(!toRemove->left && !toRemove->right) {
            *curr = nullptr;
        } else if(toRemove->left && !toRemove->right) {
            *curr = toRemove->left;
        } else if(!toRemove->left && toRemove->right) {
            *curr = toRemove->right;
        } else {
            Node** minNode = findMin(&toRemove->right);
            
            *curr = *minNode;
            *minNode = (*minNode)->right;
            
            (*curr)->left = toRemove->left;
            (*curr)->right = toRemove->right;
        }
        delete toRemove;
    }
    
    void print() const {
        CLD(root);
    }
    
    void print_odd_layers() const {
        queue<Node*> q;
        q.push(root);
        int level = 1;
        while(q.size()) {
            int s = q.size();
            for(int i = 0; i < s; i++) {
                Node* node = q.front();
                q.pop();
                if(level % 2) {
                    cout << node->data << ' ';
                }
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            level++;
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    BST bst;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str == "add") {
            int num;
            cin >> num;
            bst.add(num);
        }  else if(str == "print") {
            bst.print();
        } else if(str == "remove") {
            int num;
            cin >> num;
            bst.remove(num);
        } else {
            bst.print_odd_layers();
        }
    }
    return 0;
}
