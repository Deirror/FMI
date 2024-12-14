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
    void recFindRightMost(TreeNode* root, int level, vector<int>& vec) {
        if(!root) {
            return;
        }
        vec[level] = root->val;
        recFindRightMost(root->left, level + 1, vec);
        recFindRightMost(root->right, level + 1, vec);
    }

    int maxDepth(TreeNode* root, int level) {
        if(!root) {
            return level - 1;
        }
        return max(maxDepth(root->left, level + 1), maxDepth(root->right, level + 1));
    }

    vector<int> rightSideView(TreeNode* root) {
        int maxLevel = maxDepth(root, 1);
        if(!maxLevel) {
            return {};
        }
        vector<int> vec(maxLevel);
        recFindRightMost(root, 0, vec);
        return vec;
    }
};
