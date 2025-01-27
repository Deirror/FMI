#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left, *right;
    
    TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr) : data(data), left(left), right(right) {}
};

struct BST {
    TreeNode* root = nullptr;

    void insert(int data) {
        TreeNode** node = &root;
        while(*node) {
            if((*node)->data < data) {
                node = &(*node)->right;
            } else {
                node = &(*node)->left;
            }
        }
        *node = new TreeNode(data);
    }
      
    int height() const {
        return _height(root) - 1;
    }  
    
 private:
 int _height(TreeNode* node) const {
    if(!node) {
        return 0;
    }
    return max(_height(node->left), _height(node->right)) + 1;
 }   
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    BST bst;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        bst.insert(x);
    }
    cout << bst.height();
    return 0;
}
