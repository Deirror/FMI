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
    static bool recSumCheck(TreeNode* node, int currSum, int targetSum) {
        if(!node) {
            return false;
        }
        currSum += node->val;
        if(!node->left && !node->right) {
            return currSum == targetSum;
        }
        return recSumCheck(node->left, currSum, targetSum) || recSumCheck(node->right, currSum, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recSumCheck(root, 0, targetSum);
    }
};
