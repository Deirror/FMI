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
    void dfs(TreeNode* root, int currMax, int& counter) {
        if(!root) {
            return;
        }
        if(root->val >= currMax) {
            counter++;
            currMax = root->val;
        }
        dfs(root->left, currMax, counter);
        dfs(root->right, currMax, counter);
    }

    int goodNodes(TreeNode* root) {
        if(!root) {
            return 0;
        } else if(!root->left && !root->right) {
            return 1;
        }
        int counter = 1;
        dfs(root->left, root->val, counter);
        dfs(root->right, root->val, counter);
        return counter;
    }
};
