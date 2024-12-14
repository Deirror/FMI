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
    void recLevelPusher(TreeNode* root, int level, vector<vector<int>>& vec) {
        if(!root) {
            return;
        }
        vec[level].push_back(root->val);
        recLevelPusher(root->left, level + 1, vec);
        recLevelPusher(root->right, level + 1, vec);
    }

    int maxDepth(TreeNode* root, int level) {
        if(!root) {
            return level - 1;
        }

        return max(maxDepth(root->left, level + 1), maxDepth(root->right, level + 1));
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res(maxDepth(root, 1));
        recLevelPusher(root, 0, res);
        return res;
    }
};
