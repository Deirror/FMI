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
    int recSumLLs(TreeNode* root, bool flag = false) {
        if(!root) {
            return 0;
        }

        if(!root->left && !root->right && flag) {
            return root->val;
        }

        return recSumLLs(root->left, true) + recSumLLs(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return recSumLLs(root);
    }
};
