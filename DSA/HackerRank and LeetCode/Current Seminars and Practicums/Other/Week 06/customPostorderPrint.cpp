#include <bits/stdc++.h>

using namespace std;

vector<int> brokenRes;

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


    void print(Node *root) {
      // Note: The template MIGHT not work!!
        if(!root) {
            return;
        }      
        print(root->rightNode);
        print(root->leftNode);
        brokenRes.push_back(root->data);
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
  
    myTree.print(root);
    for(int i = 0; i < brokenRes.size() - 1; i++) {
        cout << brokenRes[i] << ';';
    }
    cout << brokenRes[brokenRes.size() - 1];
    return 0;
}
