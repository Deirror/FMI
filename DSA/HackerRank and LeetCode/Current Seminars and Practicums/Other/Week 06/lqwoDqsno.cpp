#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *leftNode;
        Node *rightNode;
        Node(int d) {
            data = d;
            leftNode = NULL;
            rightNode = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->leftNode, data);
                    root->leftNode = cur;
                } else {
                    cur = insert(root->rightNode, data);
                    root->rightNode = cur;
               }

               return root;
           }
        }
    
    void countRibs(Node* node, pair<int, int>& countLRR) {
        if(!node || (!node->leftNode && !node->rightNode)) {
            return;
        }
        
        if(node->leftNode) {
            countLRR.first++;
        }
        if(node->rightNode) {
            countLRR.second++;
        }
        countRibs(node->leftNode, countLRR);
        countRibs(node->rightNode, countLRR);
    }

	void leftRight(Node *root) {
        if(!root) {
            return;
        }
        pair<int, int> counter{0, 0};
        countRibs(root, counter);
        cout << '[' << counter.first << ',' << counter.second << ']';
    }


}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.leftRight(root);
    return 0;
}
