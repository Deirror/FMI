#include <cmath>
#include <queue>
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

int findMostLeft(TreeNode* root, int len = 0) {
    if(!root) {
        return len;
    }   
    return max(findMostLeft(root->left, len + 1), findMostLeft(root->right, len - 1));
}

int findMostRight(TreeNode* root, int len = 0) {
    if(!root) {
        return len;
    }   
    return max(findMostRight(root->left, len - 1), findMostRight(root->right, len + 1));
}

void recFillPaths(TreeNode* root, int idx, vector<int>& paths) {
    std::queue<pair<TreeNode*, int>> q;
    q.push({root, idx});
    while (q.size()) {
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        if(!paths[temp.second]) {
            paths[temp.second] = temp.first->data;
        }     
        if (temp.first->left) {
            q.push({temp.first->left, temp.second - 1});
        }
        if (temp.first->right) {
            q.push({temp.first->right, temp.second + 1});
        }
    }
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
        int maxLenMostLeft = max(findMostLeft(root->left), (findMostLeft(root->right, -1) - 1));
        int maxLenMostRight = max((findMostRight(root->left, -1) - 1), findMostRight(root->right));
        
        int size = maxLenMostLeft + maxLenMostRight + 1;
        vector<int> paths(size, 0);
        recFillPaths(root, maxLenMostLeft, paths);
        for(auto num : paths) {
            cout << num << ' ';
        }    
        cout << '\n';
    }
    return 0;
}
