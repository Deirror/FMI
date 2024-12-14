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
    void dfsReverse(TreeNode* root) {
        if(!root || (!root->left && !root->right)) {
            return;
        }
        dfsReverse(root->left);
        dfsReverse(root->right);
        swap(root->left, root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        if(!root || (!root->left && !root->right)) {
            return root;
        }
        dfsReverse(root);
        return root;
    }
};
