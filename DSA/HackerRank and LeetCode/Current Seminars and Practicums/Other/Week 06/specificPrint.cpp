#include <cmath>
#include <deque>
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

    void printSFB() {
        deque<pair<Node*, int>> dq;
        dq.push_back({root, 0});
        while(dq.size()) {
            pair<Node*, int> chekovica = (dq.back().second < dq.front().second ? dq.back() : dq.front());
            if(chekovica.second % 2 == 0) {
                pair<Node*, int> temp = dq.front();
                dq.pop_front();
                cout << temp.first->value << ' ';
                if(temp.first->left) {
                    dq.push_back({temp.first->left, temp.second + 1});
                }
                if(temp.first->right) {
                    dq.push_back({temp.first->right, temp.second + 1});
                }
            } else {
                pair<Node*, int> temp = dq.back();
                dq.pop_back();
                cout << temp.first->value << ' ';
                if(temp.first->right) {
                    dq.push_front({temp.first->right, temp.second + 1});
                }
                if(temp.first->left) {
                    dq.push_front({temp.first->left, temp.second + 1});
                }
            }
        }
    }

private:
  	//you can write helper functions if needed
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
  
    tree.printSFB();
    return 0;
}
