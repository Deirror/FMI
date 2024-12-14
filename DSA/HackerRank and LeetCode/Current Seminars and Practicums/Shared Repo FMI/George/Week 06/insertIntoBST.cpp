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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            return new TreeNode(val);
        }

        TreeNode** curr = &root;
        while(*curr) {
            if((*curr)->val < val) {
                curr = &(*curr)->right;
            } else if(val < (*curr)->val) {
                curr = &(*curr)->left;
            } else {
                return root;
            }
        }
        *curr = new TreeNode(val);
        return root;
    }
};
