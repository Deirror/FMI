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

    void printLeftProfile() {
      //TODO: implement this function
        vector<int> levels(maxDepth(root), -1);
        dfsFillVec(root, 0, levels);
        for(auto num : levels) {
            cout << num << ' ';
        }
    }

private:
  	//you can write helper functions if needed
    void dfsFillVec(Node* root, int level, vector<int>& vec) {
        if(!root) {
            return;
        }
        dfsFillVec(root->left, level + 1, vec);
        if(vec[level] == -1) {
            vec[level] = root->value;
        }
        dfsFillVec(root->right, level + 1, vec);
    }
    
    int maxDepth(Node* root) {
        if(!root) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
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
    tree.printLeftProfile();
    return 0;
}
