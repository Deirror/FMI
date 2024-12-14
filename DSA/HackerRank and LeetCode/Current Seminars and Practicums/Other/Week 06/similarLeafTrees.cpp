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
    void recFillVec(TreeNode* root, vector<int>& vec) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            vec.push_back(root->val);
            return;
        }
        recFillVec(root->left, vec);
        recFillVec(root->right, vec);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2) {
            return false;
        }
        vector<int> root1LeavesValues;
        vector<int> root2LeavesValues;
        recFillVec(root1, root1LeavesValues);
        recFillVec(root2, root2LeavesValues);
        return (root1LeavesValues == root2LeavesValues);
    }
};
