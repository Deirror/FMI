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
    void recFindMinDepth(TreeNode* root, int currLevel, int& minLevel) {
        if(!root) {
            return;
        }

        if(!root->left && !root->right) {
            minLevel = min(minLevel, currLevel);
            return;
        }
        recFindMinDepth(root->left, currLevel + 1, minLevel);
        recFindMinDepth(root->right, currLevel + 1, minLevel);
    }

    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int minLevel = int(1e5) + 1;
        recFindMinDepth(root, 1, minLevel);
        return minLevel;
    }
};
