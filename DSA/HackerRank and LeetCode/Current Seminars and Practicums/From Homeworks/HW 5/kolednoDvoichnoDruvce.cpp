#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(val), left(left), right(right) {}
};

bool isValidBTS(TreeNode* root, int minVal = -2147483648, int maxVal = 2147483647) {
    if(!root) {
        return true;
    }
    
    if(minVal >= root->val || root->val >= maxVal) {
        return false;
    }
    
    return isValidBTS(root->left, minVal, root->val) && isValidBTS(root->right, root->val, maxVal);
}

pair<TreeNode*, pair<int, int>> nodesInfo[int(1e6)];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin >> t;
    
    for(int j = 0; j < t; j++) {
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
        
        cout << isValidBTS(root) << '\n';
    }
    return 0;
}
