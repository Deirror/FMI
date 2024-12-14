#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
};

int dfs(TreeNode* root) {
    if(!root) {
        return 0;
    }
    int val = 0;
    for(int i = 0; i < root->children.size(); i++) {
       val += dfs(root->children[i]);
    }
    root->val = val;
    return val + 1;
}

TreeNode nodes[int(1e6) + 5];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    for(int i = 0; i < n - 1; i++) {
        int parent, child;
        cin >> parent >> child;
        nodes[parent].val = parent;
        nodes[child].val = child;
        nodes[parent].children.push_back(nodes + child);
    }
    
    TreeNode* root = nodes;
    dfs(root);
    for(int i = 0; i < n; i++) {
        cout << nodes[i].val << ' ';
    }
    return 0;
}
