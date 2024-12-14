/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool dfs(TreeNode* root, int minVal, int maxVal) {
        if(!root) {
            return true;
        }
        return (root->val > minVal && root->val < maxVal) 
        && dfs(root->left, minVal, root->val) 
        &&  dfs(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root->left, INT_MIN, root->val) && dfs(root->right, root->val, INT_MAX);
    }
};
