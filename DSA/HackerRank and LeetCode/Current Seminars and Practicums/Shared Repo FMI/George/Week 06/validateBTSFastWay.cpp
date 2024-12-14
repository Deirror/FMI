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
    bool recCheck(TreeNode* root, long long minVal, long long maxVal) {
        if(!root) {
            return true;
        }

        if(minVal >= root->val || root->val >= maxVal) {
            return false;
        }

        return recCheck(root->left, minVal, root->val) && recCheck(root->right,root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        if(!root || (!root->right && !root->left)) {
            return true;
        }

        return recCheck(root, LLONG_MIN, LLONG_MAX);
    }
};
