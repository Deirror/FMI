#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(val), left(left), right(right) {}
};

int lenMostLeft(TreeNode* root) {
    int counter = -1;
    while(root) {
        root = root->left;
        counter++;
    }
    return counter;
}

int lenMostRight(TreeNode* root) {
    int counter = -1;
    while(root) {
        root = root->right;
        counter++;
    }
    return counter;
}

void recPathsFill(TreeNode* root, vector<long long>& paths, int startIdx) {
    if(!root) {
        return;
    }

    paths[startIdx] += root->val;
    recPathsFill(root->left, paths, startIdx - 1);
    recPathsFill(root->right, paths, startIdx + 1);
}

//for checking if tree is linked proprerly
void postorderTraversal(TreeNode* root) {
    if(!root) {
        return;
    }
    
    cout << root->val;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
}

pair<TreeNode*, pair<int, int>> nodesInfo[int(1e6)];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a, x, y;
        cin >> a >> x >> y;
        nodesInfo[i].first = new TreeNode(a);
        nodesInfo[i].second = make_pair(x, y);
    }
    
    TreeNode* root = nodesInfo[0].first;
    for(int i = 0; i < n; i++) {
        int firstIdx = nodesInfo[i].second.first;
        int secondIdx = nodesInfo[i].second.second;
        if(firstIdx != -1 && secondIdx != -1) {
            nodesInfo[i].first->left = nodesInfo[firstIdx].first;
            nodesInfo[i].first->right = nodesInfo[secondIdx].first;
        }
    }
        
    int lenToLeft = lenMostLeft(root);
    int lenToRight = lenMostRight(root);
    
    int width = lenToLeft + lenToRight + 1;
    
    vector<long long> paths(width, 0);
    recPathsFill(root, paths, lenToLeft);
    
    for(auto num : paths) {
       cout << num << ' ';
    }
    return 0;
}
