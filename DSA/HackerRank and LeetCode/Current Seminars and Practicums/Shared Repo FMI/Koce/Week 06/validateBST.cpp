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
/*
Plan -> get max in left bt, get min in right bt and check order
*/
    void getMaxLeft(TreeNode* root, optional<int>& maxVal) {
        if(!root) {
            return;
        }
        if(!maxVal.has_value()) {
            maxVal = root->val;
        } else {
            maxVal = max(*maxVal, root->val);
        }
        getMaxLeft(root->left, maxVal);
        getMaxLeft(root->right, maxVal);
    }

    void getMinRight(TreeNode* root, optional<int>& minVal) {
        if(!root) {
            return;
        }
        if(!minVal.has_value()) {
            minVal = root->val;
        } else {
            minVal = min(*minVal, root->val);
        }
        getMinRight(root->left, minVal);
        getMinRight(root->right, minVal);
    }

    bool isValidBST(TreeNode* root) {
        if(!root || (!root->right && !root->left)) {
            return true;
        }
        optional<int> minVal;
        optional<int> maxVal;
        getMaxLeft(root->left, maxVal);
        getMinRight(root->right, minVal);
        if((maxVal.has_value() && maxVal >= root->val) || (minVal.has_value() && minVal <= root->val)) {
            return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
