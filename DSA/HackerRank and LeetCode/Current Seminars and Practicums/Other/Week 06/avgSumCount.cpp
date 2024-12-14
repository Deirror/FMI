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
    int counter = 0;
    pair<int, int> dfsAvg(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }
        if(!root->left && !root->right) {
            counter++;
            return {root->val, 1};
        }
        pair<int, int> leftPair = dfsAvg(root->left);
        pair<int, int> rightPair = dfsAvg(root->right);
        int avg = root->val + leftPair.first + rightPair.first;
        int count = 1 + leftPair.second + rightPair.second;
        if((avg / count) == root->val) {
            counter++;
        }
        return {avg, count};
     }

    int averageOfSubtree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        dfsAvg(root);
        return counter;
    }
};
