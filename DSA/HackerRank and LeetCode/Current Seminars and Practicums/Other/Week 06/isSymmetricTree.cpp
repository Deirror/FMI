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
    bool recCheckSymmetric(TreeNode* leftChild, TreeNode* rightChild) {
        if(!leftChild && !rightChild) {
            return true;
        }

        if(!leftChild || !rightChild) {
            return false;
        }

        return leftChild->val == rightChild->val && recCheckSymmetric(leftChild->left, rightChild->right) && recCheckSymmetric(leftChild->right, rightChild->left);
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right; 
        return recCheckSymmetric(leftChild, rightChild);
    }
};
