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
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(!root->left && !root->right) {
            return 1;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    bool isBalanced(TreeNode* root) {
         if(!root) {
            return true;
        }
        int maxLeftDepth = maxDepth(root->left);
        int maxRightDepth = maxDepth(root->right);
        if(abs(maxRightDepth - maxLeftDepth) > 1) {
            return false;
        } 
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
