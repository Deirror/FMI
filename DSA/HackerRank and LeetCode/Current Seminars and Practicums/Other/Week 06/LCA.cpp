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
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    
    void dfs(TreeNode* prev, TreeNode* curr, int level, int depth, TreeNode*& result) {
        if(!curr) {
            return;
        }
        dfs(curr, curr->left, level + 1, depth, result);
        dfs(curr, curr->right, level + 1, depth, result);
        if(level == depth) {
            if(prev->left && prev->right) {
                result = prev;
            } else if(!prev->left && prev->right) {
                result = prev->right;
            } else if(prev->left && !prev->right)  {
                result = prev->left;
            }   
            return;
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root || (!root->left && !root->right)) {
            return root;
        }       
        int depth = maxDepth(root);
        TreeNode* result = nullptr;
        dfs(root, root, 1, depth, result);
        return result;
    }
};
