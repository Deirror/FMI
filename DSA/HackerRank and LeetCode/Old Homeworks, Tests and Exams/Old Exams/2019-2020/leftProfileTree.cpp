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
    //helper function
    int height(Node* root) const {
        if(!root) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
    
    void LCR(Node* node, vector<int>& levels, int level) const {
        if(!node) {
            return;
        }
        if(levels[level] == -1) {
            levels[level] = node->value;
            cout << node->value << ' ';
        }
        LCR(node->left, levels, level + 1);
        LCR(node->right, levels, level + 1);
    }
public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printLeftProfile() {
        //TODO: implement this function
        int h = height(root);
        vector<int> levels(h, -1);
        LCR(root, levels, 0);
    }

private:
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
    tree.printLeftProfile();
    return 0;
}
