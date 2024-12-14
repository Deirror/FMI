#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr) : value(value), left(left), right(right) {}
};

void insert(TreeNode*& root, int value, int &size) {
    TreeNode** curr = &root;
    while(*curr) {
        if((*curr)->value < value) {
            curr = &(*curr)->right;
        } else if(value < (*curr)->value) {
             curr = &(*curr)->left;
        } else {
             return;
        }
    }
    *curr = new TreeNode(value);
    size++;
}

bool find(TreeNode* root, int value) {
    TreeNode** curr = &root;
    while(*curr) {
        if((*curr)->value < value) {
            curr = &(*curr)->right;
        } else if(value < (*curr)->value) {
             curr = &(*curr)->left;
        } else {
             return true;
        }
    }
    return false;
}

int main() {
    int start, n;
    cin >> start >> n;
    TreeNode* root = new TreeNode(start);
    int size = 1;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if(find(root, x)) {
            insert(root, y, size);
        }
    }
    cout << size;
    return 0;
}
