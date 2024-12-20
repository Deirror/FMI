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
    int maxDepth(Node *root) {
        if(!root) {
            return 0;
        }
        return 1 + max(maxDepth(root->leftNode), maxDepth(root->rightNode));
    }

	void count(Node *root) {
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        vector<int> vec(maxDepth(root), 0);
        while(q.size()) {
            auto temp = q.front();
            q.pop();
            vec[temp.second]++;
            if(temp.first->leftNode) {
                q.push({temp.first->leftNode, temp.second + 1});
            }
            if(temp.first->rightNode) {
                q.push({temp.first->rightNode, temp.second + 1});
            }
        }
        for(int i = 0; i < vec.size() - 1; i++) {
            cout << vec[i] << ';';
        }
        cout << vec[vec.size() - 1];
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
  
	myTree.count(root);
    return 0;
}
