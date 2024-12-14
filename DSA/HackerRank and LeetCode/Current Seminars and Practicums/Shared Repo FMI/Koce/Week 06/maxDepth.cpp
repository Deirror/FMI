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
    void recFindMaxDepth(TreeNode* root, int currLevel, int& maxLevel) {
        if(!root) {
            maxLevel = max(maxLevel, currLevel);
            return;
        }
        recFindMaxDepth(root->left, currLevel + 1, maxLevel);
        recFindMaxDepth(root->right, currLevel + 1, maxLevel);
    }

    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int maxLevel = 0;
        recFindMaxDepth(root, 0, maxLevel);
        return maxLevel;
    }
};
