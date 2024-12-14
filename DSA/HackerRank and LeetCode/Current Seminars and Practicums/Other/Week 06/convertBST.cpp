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
    void changeNodesValuesBST(TreeNode* root, int& previousVal) {
        if(!root) {
            return;
        }
        changeNodesValuesBST(root->right, previousVal);
        root->val += previousVal;
        previousVal = root->val;
        changeNodesValuesBST(root->left, previousVal);
    }

    TreeNode* convertBST(TreeNode* root) {
        int prevVal = 0;
        changeNodesValuesBST(root, prevVal);
        return root;
    }
};
