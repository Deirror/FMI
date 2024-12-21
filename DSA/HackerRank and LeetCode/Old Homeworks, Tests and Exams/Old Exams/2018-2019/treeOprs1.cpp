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
    
    void print() const {
        CLD(root);
        //cout << '\n';
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
        }
    }
    return 0;
}
