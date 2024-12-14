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
    int maxDepth(TreeNode* root ) {
        if(!root) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    void recVecFill(TreeNode* root, vector<int>& vec, int level) {
        if(!root) {
            return;
        }
        recVecFill(root->left, vec, level + 1);
        vec[level] = root->val;
        recVecFill(root->right, vec, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec(maxDepth(root));
        recVecFill(root, vec, 0);
        return vec;
    }
};
