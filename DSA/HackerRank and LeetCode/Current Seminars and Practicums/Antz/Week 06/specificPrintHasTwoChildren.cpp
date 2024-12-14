#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr) 
        : data(data), left(left), right(right) {}
};

void insert(TreeNode*& root, int val) {
    TreeNode** curr = &root;
    while(*curr) {
        if((*curr)->data < val) {
            curr = &(*curr)->right;
        } else if(val < (*curr)->data) {
            curr = &(*curr)->left;
        } else {
            break;
        }
    }
    *curr = new TreeNode(val);
}

void preorderTraversal(TreeNode* root) {
    if(!root) {
        return;
    }
    
    if(root->left && root->right) {
        cout << root->data << ' ';
    }
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        TreeNode* root = nullptr;
        for(int j = 0; j < n; j++) {
            int num;
            cin >> num;
            insert(root, num);       
        }           
        preorderTraversal(root);
        cout << '\n';
    }
    return 0;
}
